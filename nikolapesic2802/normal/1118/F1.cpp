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
vector<int> color(N),depth(N),checked(N);
int cnt[N][3];
vector<vector<int> > vertexes(N);
vector<vector<int> > graf(N);
int n,k;
int up[N][L];
void dfs(int tr,int par)
{
    cnt[tr][color[tr]]++;
    for(auto p:graf[tr])
    {
        if(p==par)
            continue;
        depth[p]=depth[tr]+1;
        up[p][0]=tr;
        dfs(p,tr);
        for(int i=0;i<3;i++)
            cnt[tr][i]+=cnt[p][i];
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
int main()
{
    k=2;
	scanf("%i",&n);
	vector<int> c(3);
	for(int i=0;i<n;i++)
        scanf("%i",&color[i]),vertexes[color[i]].pb(i),c[color[i]]++;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        graf[a].pb(b);
        graf[b].pb(a);
    }
    dfs(0,-1);
    int sol=0;
    for(int i=1;i<n;i++)
    {
        if(cnt[i][1]==c[1]&&cnt[i][2]==0)
            sol++;
        if(cnt[i][2]==c[2]&&cnt[i][1]==0)
            sol++;
    }
    printf("%i\n",sol);
    /*depth[0]=1;
    dfs(0,-1);
    for(int j=1;j<L;j++)
        for(int i=0;i<n;i++)
            up[i][j]=up[up[i][j-1]][j-1];
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
        for(auto p:vertexes[i])
        {
            checked[p]=1;
            if(p==l)
                continue;
            int tr=up[p][0];
            while(tr!=l&&color[tr]!=i)
            {
                if(color[tr]>0||checked[tr])
                {
                    printf("0\n");
                    return 0;
                }
                checked[tr]=1;
                tr=up[tr][0];
            }
        }
    }*/
    return 0;
}