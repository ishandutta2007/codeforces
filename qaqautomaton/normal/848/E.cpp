#include<bits/stdc++.h>
using namespace std;
typedef unsigned uint;
typedef unsigned long long ull;
typedef long long ll;

const int p=998244353,_g=3;
uint modp(uint a){return a>=p?a-p:a;}
struct Z{
	int x;
	Z(){}
	Z(int x):x(x){}
};
Z operator +(const Z &a,const Z &b){return modp(a.x+b.x);}
Z operator -(const Z &a,const Z &b){return modp(a.x+p-b.x);}
Z operator *(const Z &a,const Z &b){return static_cast<ull>(a.x)*b.x%p;}

Z operator +=(Z &a,const Z &b){return a=a+b;}
Z operator -=(Z &a,const Z &b){return a=a-b;}
Z operator *=(Z &a,const Z &b){return a=a*b;}

Z f[50005],g[50005],s0[50005],s1[50005];
Z fac[50005],inv[50005],invf[50005];
Z fw[50005];
Z f00[50005],f01[50005],f10[50005],f11[50005],S[50005];
Z C(int a,int b){return fac[a]*invf[b]*invf[a-b];}
Z w1[50005],w2[50005],w3[50005];
Z _w[1<<18|5],iN;
Z fpm(Z a,int b){Z c(1);for(;b;b>>=1,a=a*a)if(b&1)c*=a;return c;}
int N,mx=1;
int rev[1<<18|5];
void setn(int n){
	N=n;
	iN=fpm(n,p-2);
	for(int i=1;i<N;++i)rev[i]=rev[i>>1]>>1|((i&1)*(N>>1));
	while(mx<N){
		Z xw=fpm(_g,(p-1)/(mx<<1)),w=1;
		for(int i=0;i<mx;++i){_w[i+mx]=w;w*=xw;}
		mx<<=1;
	}
}
void dft(Z *_a){
	static ull a[1<<18|5];
	for(int i=0;i<N;++i)a[rev[i]]=_a[i].x;
	for(int i=1;i<N;i<<=1){
		for(int j=0;j<N;j+=i+i)for(int k=0;k<i;++k){
			ull x=a[j+k+i]*_w[i+k].x%p;
			a[j+k+i]=a[j+k]+p-x;a[j+k]+=x;
		}
	}
	for(int i=0;i<N;++i)_a[i]=a[i]%p;
}
void idft(Z *a){
	reverse(a+1,a+N);
	dft(a);
	for(int i=0;i<N;++i)a[i]*=iN;
}
Z a00[1<<18|5],a01[1<<18|5],a10[1<<18|5],a11[1<<18|5];
Z b1[1<<18|5],b2[1<<18|5],b3[1<<18|5];

void solve(int l,int r){
	if(l==r){
		f00[l]+=w1[l]*l;
		f01[l]+=w2[l]*l;
		f10[l]+=w2[l]*l;
		f11[l]+=w3[l]*l;
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid);
	int N=1;
	while(N<=r-l+1)N<<=1;
	setn(N);
	for(int i=l;i<=mid;++i){
		a00[i-l]=f00[i];
		a01[i-l]=f01[i];
		a10[i-l]=f10[i];
		a11[i-l]=f11[i];
	}
	for(int i=mid-l+1;i<N;++i){
		a00[i]=a01[i]=a10[i]=a11[i]=0;
	}
	for(int i=0;i<=r-l;++i){
		b1[i]=w1[i];b2[i]=w2[i];b3[i]=w3[i];
	}
	for(int i=r-l+1;i<N;++i){b1[i]=b2[i]=b3[i]=0;}
	dft(a00);dft(a01);dft(a10);dft(a11);
	dft(b1);dft(b2);dft(b3);
	for(int i=0;i<N;++i){
		Z u=a00[i],v=a01[i];
		a00[i]=u*b1[i]+v*b2[i];
		a01[i]=u*b2[i]+v*b3[i];
		u=a10[i],v=a11[i];
		a10[i]=u*b1[i]+v*b2[i];
		a11[i]=u*b2[i]+v*b3[i];
	}
	idft(a00);idft(a01);idft(a10);idft(a11);
	for(int i=mid+1;i<=r;++i){
		f00[i]+=a00[i-l];
		f01[i]+=a01[i-l];
		f10[i]+=a10[i-l];
		f11[i]+=a11[i-l];
	}
	solve(mid+1,r);
} 
int main(){
#ifdef QAQAutoMaton
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	if(n<2){printf("0\n");return 0;}
	S[0]=1;
	for(int i=2;i<=n;++i)S[i]=S[i-2]+(i>=4?S[i-4]:0);
	for(int i=2;i<=n;++i){
		w1[i]=S[i-1]*(i-1)*(i-1);
		w2[i]=S[i-2]*(i-1)*(i-1);
		if(i>=3)w3[i]=S[i-3]*(i-1)*(i-1);
	}
	solve(2,n);
	printf("%d\n",(f00[n]+f11[n]).x);
	return 0;
}