#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
int mod,g,invg;
int ksm(int a,int b){
	int c=1;
	while(b){
		if(b%2==1) c=1ll*c*a%mod;
		a=1ll*a*a%mod;
		b/=2;
	}
	return c;
}
using poly=vector<int>;
vector<int> rev;
vector<int> w,w2;
int invn;
void init(int n){
	rev.resize(n);
	for(int i=1;i<n;i++) rev[i]=rev[i>>1]>>1|((i&1)?n>>1:0);
	w.resize(n);
	for(int i=1;i<n;i*=2){
		w[i]=1;
		int wn=ksm(g,(mod-1)/(i*2));
		for(int j=1;j<i;j++) w[i+j]=1ll*w[i+j-1]*wn%mod;
	}
	w2.resize(n);
	for(int i=1;i<n;i*=2){
		w2[i]=1;
		int wn=ksm(invg,(mod-1)/(i*2));
		for(int j=1;j<i;j++) w2[i+j]=1ll*w2[i+j-1]*wn%mod;
	}
	invn=ksm(n,mod-2);
}
poly FFT(poly F,bool flag){
	int n=F.size();
	if(n!=(int)rev.size()) init(n);
	for(int i=0;i<n;i++) if(i<rev[i]) swap(F[i],F[rev[i]]);
	for(int i=1;i<n;i*=2) for(int j=0;j<n;j+=i*2)
		for(int k=j;k<j+i;k++){
			int t=1ll*F[k+i]*(flag?w[i+k-j]:w2[i+k-j])%mod;
			F[k+i]=(F[k]-t+mod)%mod;
			F[k]=(F[k]+t)%mod;
		}
	if(!flag) for(int i=0;i<n;i++) F[i]=1ll*F[i]*invn%mod;
	return F;
}
poly Inv(poly F){
	int n=F.size();
	if(n==1) return {ksm(F[0],mod-2)};
	poly G=Inv(poly(F.begin(),F.begin()+(n+1)/2));
	int len=1;
	while(len<n*2-1) len*=2;
	F.resize(len);
	G.resize(len);
	F=FFT(F,1);
	G=FFT(G,1);
	for(int i=0;i<len;i++) F[i]=(2-1ll*F[i]*G[i]%mod+mod)%mod*G[i]%mod;
	F=FFT(F,0);
	F.resize(n);
	return F;
}
poly Ln(poly F){
	int n=F.size();
	poly G=Inv(F);
	for(int i=0;i<n;i++) F[i]=1ll*F[i]*i%mod;
	int len=1;
	while(len<n*2-1) len*=2;
	F.resize(len);
	G.resize(len);
	F=FFT(F,1);
	G=FFT(G,1);
	for(int i=0;i<len;i++) F[i]=1ll*F[i]*G[i]%mod;
	F=FFT(F,0);
	for(int i=1;i<n;i++) F[i]=1ll*F[i]*ksm(i,mod-2)%mod;
	return F;
}
poly Exp(poly F){
	int n=F.size();
	if(n==1) return {1};
	poly G=Exp(poly(F.begin(),F.begin()+(n+1)/2));
	G.resize(n);
	poly H=Ln(G);
	int len=1;
	while(len<n*2-1) len*=2;
	F.resize(len);
	G.resize(len);
	H.resize(len);
	F=FFT(F,1);
	G=FFT(G,1);
	H=FFT(H,1);
	for(int i=0;i<len;i++) F[i]=1ll*(1-H[i]+F[i]+mod)%mod*G[i]%mod;
	F=FFT(F,0);
	F.resize(n);
	return F;
}
const int maxn=1e5+5;
int n;
poly solve(int n){
	if(n==1) return {0};
	poly F=solve((n+1)/2);
	F.resize(n);
	poly G=Exp(F);
	for(int i=n-1;i>0;i--) G[i]=G[i-1];
	G[0]=0;
	poly H(n);
	for(int i=0;i<n;i++) H[i]=(F[i]+G[i])%mod;
	H=Exp(H);
	int len=1;
	while(len<n*2-1) len*=2;
	F.resize(len);
	G.resize(len);
	H.resize(len);
	F=FFT(F,1);
	G=FFT(G,1);
	H=FFT(H,1);
	poly A=H;
	for(int i=0;i<len;i++){
		int g=G[i];
		G[i]=1ll*(F[i]+g)%mod*H[i]%mod;
		H[i]=1ll*(F[i]+g+1)%mod*((g+1)%mod)%mod;
	}
	H=FFT(H,0);
	H.resize(n);
	H.resize(len);
	H=FFT(H,1);
	for(int i=0;i<len;i++) H[i]=1ll*H[i]*A[i]%mod;
	F=FFT(F,0);
	G=FFT(G,0);
	H=FFT(H,0);
	F.resize(n);
	G.resize(n);
	H.resize(n);
	for(int i=n-1;i>0;i--) G[i]=(G[i-1]-F[i]+mod)%mod;
	G[0]=0;
	for(int i=n-1;i>0;i--) H[i]=H[i-1];
	H[0]=mod-1;
	H=Inv(H);
	G.resize(len);
	H.resize(len);
	G=FFT(G,1);
	H=FFT(H,1);
	for(int i=0;i<len;i++) G[i]=1ll*G[i]*H[i]%mod;
	G=FFT(G,0);
	for(int i=0;i<n;i++) F[i]=(F[i]-G[i]+mod)%mod;
	return F;
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	mod=read();
	int x=mod-1;
	vector<int> p;
	for(int i=2;x>1;i++) if(x%i==0){
		p.push_back(i);
		while(x%i==0) x/=i;
	}
	for(g=2;;g++){
		bool flag=ksm(g,mod-1)==1;
		if(flag) for(int i:p){
			flag&=ksm(g,(mod-1)/i)!=1;
			if(!flag) break;
		}
		if(flag) break;
	}
	invg=ksm(g,mod-2);
	poly F=solve(n+1),G=Exp(F);
	for(int i=n;i>0;i--) G[i]=G[i-1];
	G[0]=0;
	poly H(n+1);
	for(int i=0;i<=n;i++) H[i]=(F[i]+G[i])%mod;
	H=Exp(H);
	for(int i=n;i>0;i--) H[i]=(H[i-1]+F[i])%mod;
	H[0]=0;
	int len=1;
	while(len<n*2+1) len*=2;
	G.resize(len);
	H.resize(len);
	G=FFT(G,1);
	H=FFT(H,1);
	for(int i=0;i<len;i++) G[i]=1ll*G[i]*H[i]%mod;
	G=FFT(G,0);
	H=FFT(H,0);
	G.resize(n+1);
	H.resize(n+1);
	for(int i=0;i<=n;i++) G[i]=(mod*2-G[i]-H[i])%mod;
	G[0]=1;
	G=Ln(G);
	for(int i=0;i<=n;i++) H[i]=(F[i]-H[i]+mod)%mod;
	H[0]=1;
	H=Ln(H);
	for(int i=0;i<=n;i++) F[i]=(1ll*H[i]-F[i]-G[i]+mod*2)%mod;
	F=Exp(F);
	int fac=1;
	for(int i=1;i<=n;i++) fac=1ll*fac*i%mod;
	printf("%lld\n",1ll*F[n]*fac%mod);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}