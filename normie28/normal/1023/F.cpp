/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "ming.inp"
#define FILE_OUT "ming.out"
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
const int BufferSize=1<<16;
char buffer[BufferSize],*front_head,*front_tail;
inline char GET_CHAR(){
	if(front_head==front_tail){
		int l=fread(buffer,1,BufferSize,stdin);
		front_tail=(front_head=buffer)+l;
		if(front_head==front_tail)return EOF;
	}
	return *front_head++;
}
inline int READ(){
	int x=0,f=1;char c=GET_CHAR();
	for(;!isdigit(c);c=GET_CHAR()){
		if(c==EOF)return EOF;
		if(c=='-')f=-1;
	}
	for(;isdigit(c);c=GET_CHAR())x=(((x<<2)+x)<<1)+c-'0';
	return x*f;
}
const int N=500005,M=1000005;
int pre[500005];
int find(int x){return x==pre[x]?x:pre[x]=find(pre[x]);}
const int Headsize=N,Edgesize=M;
int head[Headsize+5],mal=1;
struct edge{
	int nx,to;
}e[Edgesize+5];
inline void addedge(int u,int v){
	e[mal].to=v;e[mal].nx=head[u];head[u]=mal++;
}
int Eu[N],Ev[N],Ew[N],w;
int faz[N],dep[N],deg[N];bool val[N];
long long res=0;
void dfs(int u,int f){
	dep[u]=dep[faz[u]=f]+1;
	for(int i=head[u];i;i=e[i].nx){
		int v=e[i].to;
		if(v!=f)dfs(v,u);
	}
	if(deg[u])val[u]=1,--deg[f],--deg[u];
}
int main(){
	int n,k,m,u,v;
	n=READ();k=READ();m=READ();
	for(int i=1;i<=n;i++)pre[i]=i;
	for(int i=0;i<k;i++){
		addedge(u=READ(),v=READ());addedge(v,u);
		deg[u]++;deg[v]++;
		u=find(u);v=find(v);
		pre[u]=v;
	}
	for(int i=0;i<m;i++){
		Eu[i]=u=READ();Ev[i]=v=READ();Ew[i]=READ();
		u=find(u);v=find(v);
		if(u!=v){
			addedge(Eu[i],Ev[i]);addedge(Ev[i],Eu[i]);
			pre[u]=v;
			m--;i--;
		}
	}
	dep[1]=-1;dfs(1,0);faz[1]=1;
	for(int i=1;i<=n;i++)pre[i]=i;
	for(int i=0;i<m&&k;i++){
		u=find(Eu[i]);v=find(Ev[i]);w=Ew[i];
		while(u!=v){
			if(dep[u]<dep[v])swap(u,v);
			if(val[u])val[u]=0,res+=w,k--;
			pre[u]=find(faz[u]); u=find(u);
		}
	}
	if(k)res=-1;
	printf("%I64d\n",res);
}