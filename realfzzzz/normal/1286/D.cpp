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
const int maxn=1e5+5;
int n,x[maxn],v[maxn];
const ll mod=998244353,inv100=828542813;
ll ksm(ll a,ll b){
	ll c=1;
	while(b){
		if(b%2==1) c=c*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return c;
}
ll p[maxn];
struct matrix{
	ll a[2][2];
	matrix operator *(matrix B){
		matrix C;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++){
			C.a[i][j]=0;
			for(int k=0;k<2;k++)
				C.a[i][j]=(C.a[i][j]+a[i][k]*B.a[k][j]%mod)%mod;
		}
		return C;
	}
	matrix operator -(matrix B){
		for(int i=0;i<2;i++) for(int j=0;j<2;j++)
			B.a[i][j]=(a[i][j]-B.a[i][j]+mod)%mod;
		return B;
	}
}A[maxn];
int m=0,ord[maxn*2];
pair<int,int> calc(int u){
	if(u<=n) return {x[u]-x[u-1],v[u]+v[u-1]};
	else{
		u=u<=n*2?u-n:u-n*2;
		return {x[u]-x[u-1],abs(v[u]-v[u-1])};
	}
}
struct node{
	int l,r;
	node* ch[2];
	matrix P;
	void pushup(){
		P=ch[0]->P*ch[1]->P;
	}
	node(int l,int r):l(l),r(r){
		if(l==r){
			P=A[r];
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		pushup();
	}
	void modify(int x,matrix A){
		if(l==r){
			P=A;
			return;
		}
		ch[x>=ch[1]->l]->modify(x,A);
		pushup();
	}
}*rt;
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++){
		x[i]=read();
		v[i]=read();
		p[i]=read()*inv100%mod;
	}
	if(n==1){
		printf("0\n");
		return 0;
	}
	for(int i=2;i<=n;i++){
		ord[++m]=i;
		if(v[i]>v[i-1]) ord[++m]=n+i;
		else if(v[i]<v[i-1]) ord[++m]=n*2+i;
	}
	sort(ord+1,ord+m+1,[](int a,int b){
		auto x=calc(a),y=calc(b);
		return 1ll*x.first*y.second<1ll*y.first*x.second;
	});
	for(int i=2;i<=n;i++){
		A[i].a[0][0]=A[i].a[1][0]=p[i];
		A[i].a[0][1]=A[i].a[1][1]=(1-p[i]+mod)%mod;
	}
	rt=new node(2,n);
	ll ans=0;
	for(int i=1;i<=m;i++){
		int u=ord[i];
		auto x=calc(u);
		matrix B;
		memset(B.a,0,sizeof(B.a));
		if(u<=n) B.a[0][1]=(1-p[u]+mod)%mod;
		else if(u<=n*2) B.a[1][1]=(1-p[u-=n]+mod)%mod;
		else B.a[0][0]=p[u-=n*2];
		rt->modify(u,B);
		ans=(ans+((rt->P.a[0][0]+rt->P.a[0][1])%mod*p[1]%mod+(rt->P.a[1][0]+rt->P.a[1][1])%mod*((1-p[1]+mod)%mod)%mod)%mod*(x.first%mod)%mod*ksm(x.second,mod-2)%mod)%mod;
		rt->modify(u,A[u]=A[u]-B);
	}
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}