#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353,g=3,invg=(cys+1)/3;
ll n,mc;
ll A[1100000],B[1100000],ans[1100000],a[1100000],pw[100005],r[1100000];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void ntt(ll *A,int mx,int f){
	for(int i=0;i<mx;i++) if(i<r[i]) swap(A[i],A[r[i]]);
	for(int i=1;i<mx;i<<=1){
		int wn=qpow(f>0?g:invg,(cys-1)/(i*2));
		for(int j=0;j<mx;j+=(i<<1)){
			int w=1;
			for(int k=j;k<j+i;k++,w=1ll*w*wn%cys){
				int x=A[k],y=1ll*w*A[k+i]%cys;
				A[k]=mod(x+y); A[k+i]=mod(x-y+cys);
			}
		}
	}
}

int main(){
	n=readint(); mc=readint();
	for(int i=0;i<=n;i++) a[i]=readint();
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*i%cys;
	for(int i=n;i<=n+n;i++) A[i]=pw[i-n]*a[i-n]%cys;
	for(int i=0;i<=n;i++) B[i]=qpow(pw[n-i],cys-2);
	int m=4*n,l=0,mx;
	for(mx=1;mx<=m;mx<<=1) l++;
	for(int i=0;i<mx;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	ntt(A,mx,1); ntt(B,mx,1);
	for(int i=0;i<=mx;i++) A[i]=A[i]*B[i]%cys;
	ntt(A,mx,-1);
	for(int i=n+n;i<=3*n;i++) a[i-n-n]=A[i]*qpow(mx,cys-2)%cys*qpow(pw[i-n-n],cys-2)%cys*qpow(qpow(i-n-n+1,cys-2),mc)%cys;
	memset(A,0,sizeof(A)); memset(B,0,sizeof(B));
	for(int i=n;i<=n+n;i++) A[i]=(i-n)&1?cys-pw[i-n]*a[i-n]%cys:pw[i-n]*a[i-n]%cys;
	for(int i=0;i<=n;i++) B[i]=qpow(pw[n-i],cys-2);
	ntt(A,mx,1); ntt(B,mx,1);
	for(int i=0;i<mx;i++) A[i]=A[i]*B[i]%cys;
	ntt(A,mx,-1);
	for(int i=n+n;i<=3*n;i++) ans[i-n-n]=A[i]*qpow(mx,cys-2)%cys*qpow(pw[i-n-n],cys-2)%cys*(i&1?cys-1:1)%cys;
	for(int i=0;i<=n;i++) printf("%lld\n",ans[i]);
	return 0;
}