#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=80+5;
int n,k;
ll m;
ll ksm(ll a,ll b){
	ll ans=1;
	while(b){
		if(b%2==1) ans=ans*a%m;
		a=a*a%m;
		b/=2;
	}
	return ans;
}
ll fac[maxn],ifac[maxn],pw[maxn*maxn];
ll C(int a,int b){
	return fac[a]*ifac[b]%m*ifac[a-b]%m;
}
ll f[maxn][maxn],g[maxn][maxn],h[maxn][maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	k=readint();
	m=readint();
	fac[0]=1;
	for(int i=1;i<=max(n,k);i++) fac[i]=fac[i-1]*i%m;
	ifac[max(n,k)]=ksm(fac[max(n,k)],m-2);
	for(int i=max(n,k)-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%m;
	pw[0]=1;
	for(int i=1;i<=n*k;i++) pw[i]=pw[i-1]*2%m;
	for(int a=0;a<=n;a++) for(int b=0;b<=k;b++){
		g[a][b]=1;
		for(int c=1;c<=a;c++) g[a][b]=(pw[b]-c+m)%m*g[a][b]%m;
		for(int c=0;c<b;c++) g[a][b]=(g[a][b]-g[a][c]*C(b,c)%m+m)%m;
	}
	for(int a=0;a<=n;a++) for(int b=0;b<=k;b++){
		h[a][b]=pw[a*b];
		for(int c=0;c<b;c++) h[a][b]=(h[a][b]-h[a][c]*C(b,c)%m+m)%m;
	}
	for(int a=0;a<=n;a++) for(int b=0;b<=k;b++){
		f[a][b]=h[a][b];
		for(int c=0;c<(a==n&&n%2==1?n-1:a);c++) for(int d=0;d<b;d++)
			f[a][b]=(f[a][b]-C(a,c)*C(b,d)%m*g[a-c][b-d]%m*pw[d*(a-c)]%m*f[c][d]%m+m)%m;
	}
	ll ans=0;
	for(int i=0;i<=k;i++) ans=(ans+f[n][i]*C(k,i)%m)%m;
	printf("%lld\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}