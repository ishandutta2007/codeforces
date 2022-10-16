#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
const int N=3e5+5,L=20;
vector<int> color(N),depth(N),checked(N),done(N);
vector<vector<int> > vertexes(N);
vector<vector<int> > graf(N),compressed(2*N);
int n,k;
int up[N][L];
void dfs(int tr,int par)
{
    for(auto p:graf[tr])
    {
        if(p==par)
            continue;
        depth[p]=depth[tr]+1;
        up[p][0]=tr;
        dfs(p,tr);
    }
}
int lca(int a,int b)
{
    if(depth[a]<depth[b])
        swap(a,b);
    int d=depth[a]-depth[b];
    for(int j=L-1;j>=0;j--)
        if(d>=(1<<j))
            a=up[a][j],d-=(1<<j);
    if(a==b)
        return a;
    for(int j=L-1;j>=0;j--)
        if(up[a][j]!=up[b][j])
            a=up[a][j],b=up[b][j];
    return up[a][0];
}
int mod=998244353;
int add(int x,int y)
{
    x+=y;
    if(x>=mod)
        x-=mod;
    return x;
}
int mul(int x,int y)
{
    return (ll)x*y%mod;
}
int dp[2*N][2]; ///vertex,did we cut an edge on the path between this one and the first colored one above it
void Solve(int tr,int par)
{
    if(tr<=k)
        dp[tr][1]=1;
    else
        dp[tr][0]=1;
    for(auto p:compressed[tr])
    {
        if(p==par)
            continue;
        Solve(p,tr);
        if(tr<=k)
            dp[tr][1]=mul(dp[tr][1],add(dp[p][0],dp[p][1]));
        else
        {
            dp[tr][1]=add(mul(dp[tr][1],add(dp[p][0],dp[p][1])),mul(dp[tr][0],dp[p][1]));
            dp[tr][0]=mul(dp[tr][0],add(dp[p][0],dp[p][1]));
        }
    }
    //printf("%i %i   %i %i\n",tr,par,dp[tr][0],dp[tr][1]);
}

int main()
{

    vector<int> fact;
    fact.pb(1);
	scanf("%i %i",&n,&k);
	for(int i=1;i<n;i++)
        fact.pb((ll)fact.back()*i%mod);
	for(int i=0;i<n;i++)
        scanf("%i",&color[i]),vertexes[color[i]].pb(i);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        graf[a].pb(b);
        graf[b].pb(a);
    }
    ///LCA
    depth[0]=1;
    dfs(0,-1);
    for(int j=1;j<L;j++)
        for(int i=0;i<n;i++)
            up[i][j]=up[up[i][j-1]][j-1];
    ///Color every vertex on the path from two vertexes of the same color to that color (also test if its possible to cut at all)
    for(int i=1;i<=k;i++)
    {
        int l=-1;
        for(auto p:vertexes[i])
        {
            if(l==-1)
            {
                l=p;
                continue;
            }
            l=lca(l,p);
        }
        if(checked[l])
        {
            printf("0\n");
            return 0;
        }
        checked[l]=i;
        for(auto p:vertexes[i])
        {
            checked[p]=i;
            if(p==l)
                continue;
            int tr=up[p][0];
            while(tr!=l)
            {
                if(checked[tr]==i)
                    break;
                if(checked[tr])
                {
                    printf("0\n");
                    return 0;
                }
                checked[tr]=i;
                tr=up[tr][0];
            }
        }
    }
    ///Compress
    vector<int> in(n);
    queue<int> del;
    for(int i=0;i<n;i++)
    {
        in[i]=graf[i].size();
        if(in[i]==1&&checked[i]==0)
            del.push(i);
    }
    vector<int> inside(n,1);
    while(del.size())
    {
        int tr=del.front();
        inside[tr]=0;
        del.pop();
        for(auto p:graf[tr])
        {
            in[p]--;
            if(in[p]==1&&checked[p]==0)
                del.push(p);
        }
    }
    vector<vector<int> > co(k+1);
    for(int i=0;i<n;i++)
        co[checked[i]].pb(i);
    for(int i=1;i<=k;i++)
    {
        for(auto p:co[i])
        {
            for(auto d:graf[p])
            {
                if(checked[d]!=i)
                    if(checked[d]==0){
                        if(inside[d])
                            compressed[i].pb(n+d);
                    }
                    else
                        compressed[i].pb(checked[d]);
            }
        }
    }
    for(auto p:co[0])
    {
        if(!inside[p])
            continue;
        for(auto d:graf[p])
        {
            if(checked[d]==0){
                if(inside[d])
                    compressed[n+p].pb(n+d);
            }
            else
                compressed[n+p].pb(checked[d]);
        }
    }
    ///Solve
    Solve(1,0);
    printf("%i\n",dp[1][1]);
    return 0;
}