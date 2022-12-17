#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
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
const int maxn=1e5+5;
int n,m=0,a[maxn];
typedef long long ll;
const ll mod=998244353,g=3,invg=332748118,inv2=499122177;
ll ksm(ll a,ll b){
	ll ans=1;
	while(b){
		if(b%2==1) ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans;
}
typedef vector<ll> poly;
int rev[maxn*2];
ll w[maxn*2],w2[maxn*2],invn;
void init(int n){
	for(int i=1;i<n;i++) rev[i]=rev[i>>1]>>1|((i&1)?n>>1:0);
	for(int i=1;i<n;i*=2){
		w[i]=1;
		ll wn=ksm(g,(mod-1)/(i*2));
		for(int j=1;j<i;j++) w[i+j]=w[i+j-1]*wn%mod;
	}
	for(int i=1;i<n;i*=2){
		w2[i]=1;
		ll wn=ksm(invg,(mod-1)/(i*2));
		for(int j=1;j<i;j++) w2[i+j]=w2[i+j-1]*wn%mod;
	}
	invn=ksm(n,mod-2);
}
poly FFT(poly F,bool flag){
	int n=F.size();
	for(int i=0;i<n;i++) if(i<rev[i]) swap(F[i],F[rev[i]]);
	for(int i=1;i<n;i*=2) for(int j=0;j<n;j+=i*2)
		for(int k=j;k<j+i;k++){
			ll t=F[k+i]*(flag?w[i+k-j]:w2[i+k-j])%mod;
			F[k+i]=(F[k]-t+mod)%mod;
			F[k]=(F[k]+t)%mod;
		}
	if(!flag) for(int i=0;i<n;i++) F[i]=F[i]*invn%mod;
	return F;
}
typedef vector<vector<poly>> tp;
tp solve(int l,int r){
	if(l==r){
		if(a[r]==1) return {{{0,0},{0,0}},{{0,0},{0,1}}};
		else return {{{0,2},{0,0}},{{0,0},{0,0}}};
	}
	int mid=l+(r-l)/2;
	tp F=solve(l,mid),G=solve(mid+1,r),H={{{},{}},{{},{}}},A=F,B=G;
	for(int i=0;i<2;i++){
		A[0][i][1]=(A[0][i][1]+A[1][i][1])%mod;
		A[1][i][1]=0;
		B[i][0][1]=(B[i][0][1]+B[i][1][1])%mod;
		B[i][1][1]=0;
	}
	int len=1;
	while(len<r-l+2) len*=2;
	init(len);
	for(int i=0;i<2;i++) for(int j=0;j<2;j++){
		F[i][j].resize(len);
		G[i][j].resize(len);
		F[i][j]=FFT(F[i][j],1);
		G[i][j]=FFT(G[i][j],1);
		if(r-l<=2){
			A[i][j].resize(len);
			B[i][j].resize(len);
			A[i][j]=FFT(A[i][j],1);
			B[i][j]=FFT(B[i][j],1);
		}
	}
	for(int i=0;i<2;i++) for(int j=0;j<2;j++){
		H[i][j].resize(r-l+2);
		for(int x=0;x<2;x++) for(int y=0;y<2;y++){
			poly C(len);
			for(int k=0;k<len;k++) C[k]=F[i][x][k]*G[y][j][k]%mod;
			C=FFT(C,0);
			for(int k=1;k<=r-l+1;k++) H[i][j][k]=(H[i][j][k]+C[k])%mod;
			if(r-l<=2){
				for(int k=0;k<len;k++) C[k]=A[i][x][k]*B[y][j][k]%mod;
				C=FFT(C,0);
			}
			for(int k=1;k<=r-l;k++){
				ll res=C[k+1];
				if(x&&y) res=res*2%mod;
				if(!x&&!y) res=res*inv2%mod;
				H[i][j][k]=(H[i][j][k]+res)%mod;
			}
		}
	}
	return H;
}
ll fac[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	while(n){
		a[++m]=readint();
		if(n<a[m]){
			printf("0\n");
			return 0;
		}
		for(int i=1;i<a[m];i++) if(readint()!=a[m]){
			printf("0\n");
			return 0;
		}
		n-=a[m];
	}
	fac[0]=1;
	for(int i=1;i<=m;i++) fac[i]=fac[i-1]*i%mod;
	tp F=solve(1,m);
	ll ans=0;
	for(int i=1;i<=m;i++){
		ll res=0;
		for(int j=0;j<2;j++) for(int k=0;k<2;k++) res=(res+F[j][k][i])%mod;
		ans=(ans+res*fac[i]%mod*((m-i)%2==0?1:mod-1)%mod)%mod;
	}
	printf("%lld\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}