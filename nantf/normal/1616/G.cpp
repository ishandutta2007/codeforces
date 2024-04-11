#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555555,mod=998244353;
#define MP make_pair
#define PB push_back
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
int n,m,el,head[maxn],to[maxn],nxt[maxn],r[maxn],f[maxn][2],c1[4],c2[4];
bool in[maxn];
void clear(){
	FOR(i,1,el) to[i]=nxt[i]=0;
	FOR(i,0,n+1) head[i]=r[i]=in[i]=f[i][0]=f[i][1]=0;
	FOR(i,0,3) c1[i]=c2[i]=0;
	el=0;
}
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
inline bool chk(int u,int v){
	return r[min(u,v)]>=max(u,v);
}
void solve(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		add(u,v);
		if(v==u+1) in[u]=true;
	}
	int at=0;
	FOR(i,1,n-1) if(!in[i]){at=i;break;}
	if(!at) printf("%lld\n",1ll*n*(n-1)/2);
	else{
		FOR(i,1,n+1) add(0,i);
		FOR(i,1,n) add(i,n+1);
		in[0]=in[n]=true;
		r[n+1]=n+1;
		ROF(i,n,0) r[i]=in[i]?r[i+1]:i;
		f[at][0]=1;
		f[at][1]=2;
		FOR(i,at,n+1){
			for(int e=head[i];e;e=nxt[e]){
				int j=to[e];
				if(j!=i+1 && chk(i+1,j-1)) f[j-1][1]|=f[i][0],f[j-1][0]|=f[i][1];
			}
		}
		ROF(i,at-1,0){
			for(int e=head[i];e;e=nxt[e]){
				int j=to[e];
				if(j!=i+1 && chk(i+1,j-1)) f[i][1]|=f[j-1][0],f[i][0]|=f[j-1][1];
			}
		}
		ll ans=0;
		FOR(i,0,at) if(chk(0,i)) c1[f[i][0]]++;
		FOR(i,at+1,n+1) if(chk(i,n+1)) c2[f[i-1][0]]++;
		FOR(i,0,3) FOR(j,0,3) if(i&j) ans+=1ll*c1[i]*c2[j];
		FOR(i,at-1,at+1) FOR(j,at-1,i) if(chk(0,i-1) && chk(j+1,n+1) && (f[i-1][0]&f[j][0])) ans--;
		printf("%lld\n",ans);
	}
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}