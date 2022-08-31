#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
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

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353,g=3,invg=(cys+1)/g;
int n,k,N,l;
ll fac[100005],inv[100005];
int A[300000],B[300000],r[300000];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void init(int m){
	l=0;
	for(N=1;N<m;N<<=1) l++;
	for(int i=1;i<N;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
}

void ntt(int *A,int N,int f){
	for(int i=1;i<N;i++) if(i<r[i]) swap(A[i],A[r[i]]);
	for(int i=1;i<N;i<<=1){
		int wn=qpow(f>0?g:invg,(cys-1)/(i<<1));
		for(int j=0;j<N;j+=(i<<1)){
			for(int k=j,w=1;k<j+i;k++,w=1ll*w*wn%cys){
				int x=A[k],y=1ll*w*A[k+i]%cys;
				A[k]=mod(x+y); A[k+i]=mod(x+cys-y);
			}
		}
	}
	if(f<0){
		ll invn=qpow(N,cys-2);
		for(int i=0;i<N;i++) A[i]=A[i]*invn%cys;
	}
}

int main(){
	n=readint(); k=readint();
	fac[0]=inv[0]=1;
	for(int i=1;i<=k;i++) fac[i]=fac[i-1]*i%cys;
	inv[k]=qpow(fac[k],cys-2);
	for(int i=k-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	for(int i=0;i<=k;i++) A[i]=i&1?cys-inv[i]:inv[i];
	for(int i=0;i<=k;i++) B[i]=qpow(i,k)*inv[i]%cys;
	init(k+k+1);
	ntt(A,N,1); ntt(B,N,1);
	for(int i=0;i<N;i++) A[i]=1ll*A[i]*B[i]%cys;
	ntt(A,N,-1);
	ll now=1,ans=0;
	for(int i=1;i<=k;i++){
		now=now*(n-i+1)%cys;
		if(!now) break;
		ans=(ans+A[i]*now%cys*qpow(n+1,n-i))%cys;
	}
	printf("%lld\n",ans);
	return 0;
}