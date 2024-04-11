#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxm=100005;
const int Maxn=1505;
const LL mod=1e9+7;
LL qp(LL x,LL p){
	LL ret=1;
	while (p){
		if (p&1) ret=ret*x%mod;
		p>>=1;
		x=x*x%mod;
	}
	return ret;
}
LL inv(LL x){
	return qp(x,mod-2);
}
LL fact[Maxm],ivf[Maxm];
void _init(){
	fact[0]=1;
	for (int i=1;i<Maxm;i++) fact[i]=fact[i-1]*i%mod;
	for (int i=0;i<Maxm;i++) ivf[i]=inv(fact[i]);
}
LL C(LL x,LL y){
	if (x<y) return 0;
	return fact[x]*ivf[y]%mod*ivf[x-y]%mod;
}
LL P[Maxn],Q[Maxn],SP[Maxn],SQ[Maxn];
LL F[Maxn],h[Maxn][Maxn],g[Maxn][Maxn],hs[Maxn][Maxn],gs[Maxn][Maxn];
LL Hs[Maxn][Maxn],Gs[Maxn][Maxn];
int n,m,k;
LL p;
void Add(LL &x,LL y){
	x+=y;
	if (x>=mod) x-=mod;
}
void Pre(int i){
	for (int j=1;j<=m;j++){
		gs[i][j]=gs[i][j-1]+g[i][j];
		if (gs[i][j]>=mod) gs[i][j]-=mod;
	}
	for (int j=1;j<=m;j++){
		Gs[i][j]=Gs[i][j-1]+g[i][j]*SP[j]%mod;
		if (Gs[i][j]>=mod) Gs[i][j]-=mod;
	}
	for (int j=m;j>=1;j--){
		hs[i][j]=hs[i][j+1]+h[i][j];
		if (hs[i][j]>=mod) hs[i][j]-=mod;
	}
	for (int j=m;j>=1;j--){
		Hs[i][j]=Hs[i][j+1]+h[i][j]*SQ[j]%mod;
		if (Hs[i][j]>=mod) Hs[i][j]-=mod;
	}
	F[i]=0;
	for (int j=1;j<=m;j++) Add(F[i],h[i][j]);
}
int main(){
	_init();
	scanf("%d %d",&n,&m);
	int _,__;
	scanf("%d %d",&_,&__);
	p=_*inv(__)%mod;
	scanf("%d",&k);
//	cout<<fact[4]<<' '<<ivf[4]*fact[4]%mod<<endl;
//	cout<<C(10,5)<<endl;
	for (int i=1;i<=m;i++){
		if(i-1<=k) P[i]=C(k,i-1)*qp(p,i-1)%mod*qp(mod+1-p,k-i+1)%mod;
		if(m-i<=k) Q[i]=C(k,m-i)*qp(p,m-i)%mod*qp(mod+1-p,k-m+i)%mod;
		//cout<<i<<' '<<P[i]<<' '<<Q[i]<<endl;
	}
	for (int i=1;i<=m;i++){
		SP[i]=SP[i-1]+P[i];
		if (SP[i]>=mod) SP[i]-=mod;
	}
	for (int i=m;i>=1;i--){
		SQ[i]=SQ[i+1]+Q[i];
		if (SQ[i]>=mod) SQ[i]-=mod;
	}
	h[0][1]=1;g[0][m]=1;
	for (int i=1;i<=n;i++){
		Pre(i-1);
		for (int r=1;r<=m;r++){
			g[i][r]=SP[r]*F[i-1]-SP[r]*gs[i-1][r-1]+Gs[i-1][r-1]-SP[r]*hs[i-1][r+1];
			g[i][r]=g[i][r]%mod*Q[r]%mod;
			g[i][r]=(g[i][r]%mod+mod)%mod;
		}
		for (int l=1;l<=m;l++){
			h[i][l]=SQ[l]*F[i-1]-SQ[l]*gs[i-1][l-1]-SQ[l]*hs[i-1][l+1]+Hs[i-1][l+1];
			h[i][l]=h[i][l]%mod*P[l]%mod;
			h[i][l]=(h[i][l]%mod+mod)%mod;
		}
	}
	Pre(n);
	printf("%lld\n",F[n]);
	return 0;
}