#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=10001000,mod=1000000007;
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
int n,v,c[maxn],pw[maxn],pr[maxn/10],pl,mu[maxn],g[maxn],f1,ans;
bool vis[maxn];
void init(int upr){
	mu[1]=1;
	FOR(i,2,upr){
		if(!vis[i]) mu[pr[++pl]=i]=-1;
		FOR(j,1,pl){
			int k=i*pr[j];
			if(k>upr) break;
			vis[k]=true;
			if(i%pr[j]) mu[i*pr[j]]=-mu[i];
			else break;
		}
	}
	FOR(i,1,upr) if(mu[i]==-1) mu[i]=mod-1;
	pw[0]=1;
	FOR(i,1,upr) pw[i]=(pw[i-1]+pw[i-1])%mod;
}
void is_this_fmt(int *A){
	FOR(i,1,pl) ROF(j,v/pr[i],1) A[j]=(A[j]+A[j*pr[i]])%mod;
}
int main(){
	n=read();
	while(n--){
		int x=read();
		c[x]++;
		v=max(v,x);
	}
	init(v);
	is_this_fmt(c);
	FOR(i,1,v) g[i]=(pw[c[i]]-1+mod)%mod;
	FOR(i,1,v) f1=(f1+1ll*mu[i]*g[i])%mod;
	g[1]=(g[1]-f1+mod)%mod;
	FOR(i,1,v) ans=(ans+1ll*mu[i]*c[i]%mod*g[i])%mod; 
	printf("%d\n",ans);
}