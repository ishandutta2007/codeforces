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
int n,m,k,c[501],pos[100001],t,t1,i,j,dis[501][501],ine[501][501],res[501][501];
vector<piii> e;
int main()
{
//  ofile;
    fio;
    cin>>n>>m;
    for (i=1;i<=n;i++) for (j=1;j<=n;j++) dis[i][j]=1e9;
    for (i=1;i<=n;i++) dis[i][i]=0;
    for (i=1;i<=m;i++)
    {
    	int a,b,d;
    	cin>>a>>b>>d;
    	dis[a][b]=d;
    	dis[b][a]=d;
    	e.push_back({a,{b,d}});
    }
    for (k=1;k<=n;k++) for (i=1;i<=n;i++) for (j=1;j<=n;j++)
    {
    	dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    for (i=1;i<=n;i++)
    for (auto g:e)
    {
    	if (dis[i][g.p1]+g.p3==dis[i][g.p2]) ine[i][g.p2]++;
    	if (dis[i][g.p2]+g.p3==dis[i][g.p1]) ine[i][g.p1]++;
    }
    for (i=1;i<=n;i++) for (j=1;j<=n;j++) for (k=1;k<=n;k++)
    {
    	if (dis[i][k]+dis[k][j]==dis[i][j]) res[i][j]+=ine[i][k];
    }
    for (i=1;i<=n;i++) for (j=i+1;j<=n;j++) cout<<res[i][j]<<' ';
}
//abbbbbaaba