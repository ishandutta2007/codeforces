#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,m,K,cys;
ll a[50005],tmp[50005];
pll b[50005];

struct matrix{
	ll a[2][2];
	matrix(ll a00=0,ll a01=0,ll a10=0,ll a11=0){a[0][0]=a00,a[0][1]=a01,a[1][0]=a10,a[1][1]=a11;}
	matrix operator*(const matrix c)const{
		matrix ret;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) ret.a[i][j]=(ret.a[i][j]+a[i][k]*c.a[k][j])%cys;
		return ret;
	}
}mt[150000];

void build(int id,int l,int r){
	if(l==r) return (void)(mt[id]=matrix(0,a[l],1,a[l+1]));
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	mt[id]=mt[id<<1]*mt[id<<1|1];
}

void change(int id,int l,int r,int x,matrix c){
	if(l==r) return (void)(mt[id]=c);
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x,c);
	else change(id<<1|1,mid+1,r,x,c);
	mt[id]=mt[id<<1]*mt[id<<1|1];
}

matrix query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return mt[id];
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return query(id<<1,l,mid,ql,mid)*query(id<<1|1,mid+1,r,mid+1,qr);
}

matrix qpow(matrix x,ll p){
	matrix ret;
	ret.a[0][0]=ret.a[1][1]=1;
	for(;p;p>>=1,x=x*x) if(p&1) ret=ret*x;
	return ret;
}

int main(){
	K=readint(); cys=readint(); n=readint();
	if(K==0) return printf("0\n"),0;
	K--;
	for(int i=1;i<=n;i++) tmp[i]=a[i]=readint()%cys;
	a[n+1]=tmp[n+1]=a[1];
	build(1,1,n);
	m=readint();
	for(int i=1;i<=m;i++) b[i].fi=readint(),b[i].se=readint()%cys;
	sort(b+1,b+m+1);
	if(b[1].fi==n) change(1,1,n,n,matrix(0,a[n],1,b[1].se));
	if(K<n) return printf("%lld\n",(matrix(0,1,0,0)*query(1,1,n,1,K+1)).a[0][0]),0;
	matrix ans=matrix(0,1,0,0)*mt[1];
	if(b[1].fi==n) change(1,1,n,n,matrix(0,a[n],1,a[n+1]));
	for(int i=1,j;i<=m;i=j+1){
		j=i;
		while(b[j+1].fi/n==b[j].fi/n) j++;
		if(K/n<b[i].fi/n){
			ans=ans*qpow(mt[1],K/n-b[i-1].fi/n-1);
			ans=ans*query(1,1,n,1,K%n+1);
			printf("%lld\n",ans.a[0][0]);
			return 0;
		}
		if(b[i].fi%n!=0) ans=ans*qpow(mt[1],b[i].fi/n-b[i-1].fi/n-1);
		else{
			if(b[i].fi/n-b[i-1].fi/n>1){
				ans=ans*qpow(mt[1],b[i].fi/n-b[i-1].fi/n-2);
				change(1,1,n,n,matrix(0,a[n],1,b[i].se));
				ans=ans*mt[1];
				change(1,1,n,n,matrix(0,a[n],1,a[n+1]));
			}
		}
		for(int k=i;k<=j;k++){
			a[b[k].fi%n+1]=b[k].se;
			change(1,1,n,b[k].fi%n+1,matrix(0,a[b[k].fi%n+1],1,a[b[k].fi%n+2]));
			if(b[k].fi%n!=0) change(1,1,n,b[k].fi%n,matrix(0,a[b[k].fi%n],1,a[b[k].fi%n+1]));
		}
		if(j<m&&b[j+1].fi==(b[i].fi/n)*n+n) change(1,1,n,n,matrix(0,a[n],1,b[j+1].se));
		if(K/n==b[i].fi/n) return printf("%lld\n",(ans*query(1,1,n,1,K%n+1)).a[0][0]),0;
		ans=ans*mt[1];
		if(j<m&&b[j+1].fi==(b[i].fi/n)*n+n) change(1,1,n,n,matrix(0,a[n],1,a[n+1]));
		for(int k=i;k<=j;k++){
			a[b[k].fi%n+1]=tmp[b[k].fi%n+1];
			change(1,1,n,b[k].fi%n+1,matrix(0,a[b[k].fi%n+1],1,a[b[k].fi%n+2]));
			if(b[k].fi%n!=0) change(1,1,n,b[k].fi%n,matrix(0,a[b[k].fi%n],1,a[b[k].fi%n+1]));
		}
	}
	ans=ans*qpow(mt[1],K/n-b[m].fi/n-1);
	ans=ans*query(1,1,n,1,K%n+1);
	printf("%lld\n",ans.a[0][0]);
	return 0;
}