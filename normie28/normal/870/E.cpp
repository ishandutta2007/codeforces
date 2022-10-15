
// Problem : E. Points, Lines and Ready-made Titles
// Contest : Codeforces - Technocup 2018 - Elimination Round 2
// URL : https://codeforces.com/problemset/problem/870/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int N = 100005;
int pts[2][N],pt[N];
vector<int> graph[N];
unordered_set<int> x,y;
bool vis[N],cyc;
ll md = 1e9 + 7;
ll power(ll a,ll b,ll mod)
{
    if(b==0)
      return 1;
    ll p = power(a,b/2,mod);
    p = (p*p)%mod;
    if(b&1)
      p = (p*a)%mod;
    return p;
}
inline bool cmp(const int &i,const int &j)
{
    return (pts[0][i]==pts[0][j])? pts[1][i]<pts[1][j]: pts[0][i]<pts[0][j];
}
inline bool cmp1(const int &i,const int &j)
{
    return (pts[1][i]==pts[1][j])? pts[0][i]<pts[0][j]: pts[1][i]<pts[1][j];
}
void dfs(int u,int p)
{
    vis[u] = 1;
    x.insert(pts[0][u]);
    y.insert(pts[1][u]);
    for(int v:graph[u])
    {
        if(v==p)continue;
        if(vis[v])
          cyc = 1;
        else
          dfs(v,u);
    }
}
int main()
{
	fio;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>pts[0][i]>>pts[1][i],pt[i] = i;
    sort(pt+1,pt+n+1,cmp);
    for(int i=2;i<=n;i++)
    {
        if(pts[0][pt[i]]==pts[0][pt[i-1]])
          graph[pt[i]].push_back(pt[i-1]),graph[pt[i-1]].push_back(pt[i]);
    }
    sort(pt+1,pt+n+1,cmp1);
    for(int i=2;i<=n;i++)
    {
        if(pts[1][pt[i]]==pts[1][pt[i-1]])
          graph[pt[i]].push_back(pt[i-1]),graph[pt[i-1]].push_back(pt[i]);
    }
    ll ans = 1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
         {dfs(i,-1);ans = (cyc)? (ans*power(2,(ll)x.size()+y.size(),md))%md : (ans*(power(2,(ll)x.size()+y.size(),md)-1))%md;x.clear();y.clear();cyc = 0;}
    }
    cout<<ans;
    return 0;
}