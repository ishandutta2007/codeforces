#include<bits/stdc++.h>
typedef long long ll;
#define all(x) (x).begin(),(x).end()
#define pr std::pair<int,int>
#define fi first
#define se second
#define mod 1000000007
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
ll gi(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int d[51],sd[51],fact[51],ifact[51];
int C(int n,int m){return 1ll*fact[n]*ifact[m]%mod*ifact[n-m]%mod;}
int D(int n,int m){
	if(m==0)return!n;
	return C(n-1,m-1);
}
int f[51][51],g[51][51][51];
void inc(int&x,int y){x=x+y>=mod?x+y-mod:x+y;}
int main(){
	int n=gi();
	for(int i=1;i<=n;++i)d[i]=gi()-(i>1),sd[i]=sd[i-1]+d[i];
	fact[0]=1;for(int i=1;i<=n;++i)fact[i]=1ll*i*fact[i-1]%mod;
	ifact[n]=pow(fact[n],mod-2);for(int i=n;i;--i)ifact[i-1]=1ll*ifact[i]*i%mod;
	for(int a=0;a+a<=n;++a)
		for(int b=0;b<=n;++b){
			if(!a&&!b)g[0][a+a][b]=1;
			else
			for(int j=0;j<=b;++j){
				if(a)inc(g[0][a+a][b],1ll*g[0][a+a-2][b-j]*C(b,j)%mod*fact[j]%mod*(a+a-1)%mod);
				else if(j>2)inc(g[0][a+a][b],1ll*g[0][a+a][b-j]*C(b-1,j-1)%mod*fact[j-1]%mod*(mod+1>>1)%mod);
			}
		}
	for(int i=1;i<=n;++i)
		for(int a=0;a<=n;++a)
			for(int b=0;b<=n;++b){//ad=1bd=2i
				if(a)inc(g[i][a][b],1ll*a*g[i-1][a-1][b]%mod);//d=1
				if(b)inc(g[i][a][b],1ll*b*g[i-1][a+1][b-1]%mod);//d=2
			}
	f[2][d[1]+1]=1;
	for(int i=2;i<=n;++i){
		for(int j=1;j<=i;++j){//last [j,i]
			if(!f[j][i])continue;
			//fprintf(stderr,"%d %d %d\n",j,i,f[j][i]);
			int s2=sd[i]-sd[j-1]-(i-j+1),s1=i-j+1-s2;
			for(int k=i+1;k<=n;++k)inc(f[i+1][k],1ll*f[j][i]*g[k-i][s1][s2]%mod);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		int s2=sd[n]-sd[i-1]-(n-i+1),s1=n-i+1-s2;
		inc(ans,1ll*f[i][n]*g[0][s1][s2]%mod);
	}
	printf("%d\n",ans);
	return 0;
}