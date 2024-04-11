#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
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
int n,x[maxn],y[maxn],tp[maxn],f[maxn],s[maxn],ans;
int main(){
	n=read();
	FOR(i,1,n) x[i]=read(),y[i]=read(),tp[i]=read();
	FOR(i,1,n){
		f[i]=(x[i]-y[i])%mod;
		int j=lower_bound(x+1,x+n+1,y[i])-x;
		f[i]=(f[i]+(s[i-1]-s[j-1]+mod)%mod)%mod;
		s[i]=(s[i-1]+f[i])%mod;
		if(tp[i]) ans=(ans+f[i])%mod;
	}
	ans=(ans+x[n]+1)%mod;
	printf("%d\n",ans);
}