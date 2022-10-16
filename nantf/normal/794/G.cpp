#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=666666,mod=1000000007;
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
int n,cl,dl,x,y,a,b,mu[maxn],pr[maxn],pl,fac[maxn],invfac[maxn];
char c[maxn],d[maxn];
bool vis[maxn];
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
int calc(int n){
	int ans=0;
	for(int l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		ans=(ans+1ll*(n/l)*(n/l)%mod*(mu[r]-mu[l-1]+mod))%mod;
	}
	return ans;
}
int f(int a,int b){
	if(a<0) a=-a,b=-b;
	if(b<0) return 0;
	if(!a && !b){
		int ans=0;
		for(int l=1,r;l<=n;l=r+1){
			r=n/(n/l);
			ans=(ans+1ll*calc(n/l)*(qpow(2,r+1)-qpow(2,l)+mod))%mod;
		}
		return ans;
	}
	if(!a || !b) return 0;
	int t=1ll*n*gcd(a,b)/max(a,b)%(mod-1);
	return (qpow(2,t+1)-2+mod)%mod;
}
inline int C(int n,int m){
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int main(){
	scanf("%s%s",c+1,d+1);
	cl=strlen(c+1);
	dl=strlen(d+1);
	FOR(i,1,cl){
		if(c[i]=='?') x++;
		if(c[i]=='A') a++;
		if(c[i]=='B') b--;
	}
	FOR(i,1,dl){
		if(d[i]=='?') y++;
		if(d[i]=='A') a--;
		if(d[i]=='B') b++;
	}
	n=read();
	mu[1]=1;
	FOR(i,2,n){
		if(!vis[i]) pr[++pl]=i,mu[i]=-1;
		FOR(j,1,pl){
			int k=i*pr[j];
			if(k>n) break;
			vis[k]=true;
			if(i%pr[j]) mu[k]=-mu[i];
			else break;
		}
	}
	FOR(i,2,n) mu[i]=(mu[i]+mu[i-1]+mod)%mod;
	fac[0]=1;
	FOR(i,1,x+y) fac[i]=1ll*fac[i-1]*i%mod;
	invfac[x+y]=qpow(fac[x+y],mod-2);
	ROF(i,x+y-1,0) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	int ans=0;
	FOR(i,0,x+y) ans=(ans+1ll*C(x+y,i)*f(a-y+i,b-x+i))%mod;
	if(cl==dl){
		int pr=1;
		FOR(i,1,cl) if(c[i]==d[i]){
			if(c[i]=='?') pr=pr*2%mod;
		}
		else{
			if(min(c[i],d[i])=='A' && max(c[i],d[i])=='B') pr=0;
		}
		ans=(ans+1ll*pr*(qpow((qpow(2,n+1)-2+mod)%mod,2)-f(0,0)+mod))%mod;
	}
	printf("%d\n",ans);
}