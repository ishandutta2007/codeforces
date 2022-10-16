#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444444,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,m,el,head[maxn],to[maxn],nxt[maxn],deg[maxn],col[maxn],q[maxn],h=1,r;
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void clear(){
	FOR(i,1,n) head[i]=deg[i]=col[i]=q[i]=0;
	h=1;r=0;
	FOR(i,1,el) to[i]=nxt[i]=0;
	el=0;
}
void solve(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		add(u,v);
		deg[v]++;
	}
	FOR(i,1,n) if(!deg[i]) col[i]=1,q[++r]=i;
	while(h<=r){
		int u=q[h++];
//		printf("col[%d]=%d\n",u,col[u]);
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(col[u]==1){
				col[v]=max(col[v],2);
			}
			else if(col[u]==2){
				col[v]=max(col[v],3);
			}
			else{
				col[v]=max(col[v],1);
			}
			if(!--deg[v]) q[++r]=v;
		}
	}
	int cnt=0;
	FOR(i,1,n) if(col[i]==3) cnt++;
	printf("%d\n",cnt);
	FOR(i,1,n) if(col[i]==3) printf("%d ",i);
	puts("");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}