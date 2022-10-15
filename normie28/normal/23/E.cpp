
// Problem : E. Tree
// Contest : Codeforces - Codeforces Beta Round #23
// URL : https://codeforces.com/problemset/problem/23/E
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
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep2(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define REP(i,a,b) for(int i=(a);i>=(b);--i)
#define REP2(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
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
#define inf 1000000000
#define MAX 300001
#define mag 320
#define mp make_pair
#define pb push_back
#define r1 rt<<1
#define r2 rt<<1|1
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
const int N=705,bit=10000;
struct edg{int nxt,to;}e[N<<1];int head[N],cnt,sz[N],n;
struct number{int a[40];}ans,f[N][N];
inline number operator * (number x,number y){
	number z;memset(z.a,0,sizeof z.a);
	rep(i,1,x.a[0])
		rep(j,1,y.a[0])
			z.a[i+j-1]+=x.a[i]*y.a[j];
	z.a[0]=x.a[0]+y.a[0]-1;
	rep(i,1,z.a[0]) z.a[i+1]+=z.a[i]/bit,z.a[i]%=bit;
	if(z.a[z.a[0]+1]) ++z.a[0];
	return z;
}
inline number maxx(number x,number y){
	if(x.a[0]>y.a[0]) return x;
	if(x.a[0]<y.a[0]) return y;
	REP(i,x.a[0],1)
		if(x.a[i]>y.a[i]) return x;
		else if(x.a[i]<y.a[i]) return y;
	return x;
}
inline number change(int x){number t;t.a[0]=1;t.a[1]=x;return t;}
inline void add(int u,int v){e[++cnt]=(edg){head[u],v};head[u]=cnt;}
inline void dfs(int u,int fa){
	sz[u]=1;f[u][1].a[0]=f[u][1].a[1]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;if(v==fa) continue;
		dfs(v,u);
		REP(j,sz[u],0)
			REP(k,sz[v],0)
				f[u][j+k]=maxx(f[u][j+k],f[u][j]*f[v][k]);
		sz[u]+=sz[v];
	}
	f[u][0]=change(sz[u]);
	rep(i,1,sz[u]) f[u][0]=maxx(f[u][0],f[u][i]*change(i));
}
inline void print(number x){
	printf("%d",x.a[x.a[0]]);
	REP(i,x.a[0]-1,1) printf("%.4d",x.a[i]);
}
 
int main()
{
	cin>>n;
	for (int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);add(v,u);
	}
	dfs(1,0);
	print(f[1][0]);
}