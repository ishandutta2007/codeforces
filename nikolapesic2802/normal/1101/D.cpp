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

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
const int N=2e5+5;
vector<vector<int> > graf(N),drvo(N);
vector<int> visited(N),siz(N),a(N);
void dfs(int tr,int par)
{
    siz[tr]=1;
    for(auto p:graf[tr])
    {
        if(visited[p]||p==par)
            continue;
        dfs(p,tr);
        siz[tr]+=siz[p];
    }
}
int find_centroid(int tr,int n,int par)
{
    for(auto p:graf[tr])
    {
        if(p==par||visited[p])
            continue;
        if(siz[p]>n/2)
            return find_centroid(p,n,tr);
    }
    return tr;
}
int decompose(int tr)
{
    dfs(tr,-1);
    tr=find_centroid(tr,siz[tr],-1);
    visited[tr]=1;
    for(auto p:graf[tr])
    {
        if(visited[p])
            continue;
        int t=decompose(p);
        //printf("%i--%i\n",tr,t);
        drvo[t].pb(tr);
        drvo[tr].pb(t);
    }
    return tr;
}
vector<int> sito(N);vector<vector<int> > factors(N);vector<int> vis(N);
int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
set<pair<int,int> > possible;
void calc(int tr,int par,int g,int d)
{
    //printf("%i %i %i %i\n",tr,par,g,d);
    if(g==1)
        return;
    possible.insert({d,g});
    for(auto p:graf[tr])
    {
        if(p==par||vis[p]==1)
            continue;
        calc(p,tr,gcd(g,a[p]),d+1);
    }
}
int solve(int tr,int par)
{
    map<int,int> m;
    set<int> dodato;
    vis[tr]=1;
    int sol=0;
    for(auto p:graf[tr])
    {
        if(vis[p]==1)
            continue;
        possible.clear();
        calc(p,tr,gcd(a[tr],a[p]),1);
        for(auto p1:possible)
        {
            for(auto d:factors[p1.s])
            {
                sol=max(sol,m[d]+p1.f+1);
            }
        }
        for(auto p1:possible)
        {
            for(auto d:factors[p1.s])
            {
                dodato.insert(d);
                if(p1.f>m[d])
                    m[d]=p1.f;
            }
        }
    }
    for(auto p:drvo[tr])
    {
        if(p==par)
            continue;
        sol=max(sol,solve(p,tr));
    }
    return sol;
}
void print(int tr,int par)
{
    for(auto p:drvo[tr])
    {
        if(p==par)
            continue;
        printf("%i--%i\n",tr,p);
        print(p,tr);
    }
}
int main()
{
    for(int i=2;i<N;i++)
    {
        if(sito[i]!=0)
            continue;
        for(int j=i;j<N;j+=i)
            sito[j]=i;
    }
    for(int i=2;i<N;i++)
    {
        int tr=i;
        while(tr!=1)
        {
            factors[i].pb(sito[tr]);
            tr/=sito[tr];
        }
    }
	int n;
	scanf("%i",&n);
	int maxx=0;
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]),maxx=max(maxx,a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%i %i",&x,&y);
        x--;
        y--;
        graf[x].pb(y);
        graf[y].pb(x);
    }
    int root=decompose(0);
    //print(root,-1);
    int r=solve(root,-1);
    if(r==0)
    {
        if(maxx==1)
            printf("0\n");
        else
            printf("1\n");
    }
    else
        printf("%i\n",r);
    return 0;
}