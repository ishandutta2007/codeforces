#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int ans=1,k,inv[51];
struct matrix{
	int s[50][50];
	matrix(){memset(s,0,sizeof s);}
};
matrix operator*(const matrix&A,const matrix&B){
	matrix r;
	for(int j=0;j<50;++j)
		for(int i=0;i<50;++i)
			for(int k=0;k<50;++k)
				r.s[i][k]=(r.s[i][k]+1ll*A.s[i][j]*B.s[j][k])%mod;
	return r;
}
matrix operator^(matrix A,int b){
	matrix r;for(int i=0;i<50;++i)r.s[i][i]=1;
	while(b){
		if(b&1)r=r*A;
		A=A*A;b>>=1;
	}
	return r;
}
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int work(ll p,int e){
	p%=mod;
	matrix S,T;
	S.s[0][e]=1;
	for(int i=0;i<=e;++i)for(int j=0;j<=i;++j)T.s[i][j]=inv[i+1];
	S=S*(T^k);
	int ret=0;
	for(int i=0,pp=1;i<=e;++i,pp=1ll*pp*p%mod)ret=(ret+1ll*pp*S.s[0][i])%mod;
	return ret;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	ll n=gi();k=gi();
	for(int i=0;i<=50;++i)inv[i]=pow(i,mod-2);
	for(int i=2;1ll*i*i<=n;++i)
		if(n%i==0){
			int e=0;while(n%i==0)++e,n/=i;
			ans=1ll*ans*work(i,e)%mod;
		}
	if(n>1)ans=1ll*ans*work(n,1)%mod;
	printf("%d\n",ans);
	return 0;
}