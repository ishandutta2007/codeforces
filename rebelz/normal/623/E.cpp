#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
const ld pi=acos(-1);
int n,k;
ll fac[30005],inv[30005];
vector<ll> pl[17],tmp;

namespace MTT{
	struct node{
		ld x,y;
		node(ld x=0,ld y=0):x(x),y(y){}
		node operator+(const node c)const{return node(x+c.x,y+c.y);}
		node operator-(const node c)const{return node(x-c.x,y-c.y);}
		node operator*(const node c)const{return node(x*c.x-y*c.y,x*c.y+y*c.x);}
	}A1[70000],B1[70000],A2[70000],B2[70000],C1[70000],C2[70000],C3[70000];
	int n,l,tcys=32768;
	int r[70000];
	void FFT(node *A,int n,int f){
		for(int i=0;i<n;i++) if(i<r[i]) swap(A[i],A[r[i]]);
		for(int i=1;i<n;i<<=1){
			node wn(cos(pi/i),f*sin(pi/i));
			for(int j=0;j<n;j+=(i<<1)){
				node w(1,0);
				for(int k=j;k<j+i;k++,w=w*wn){
					node x=A[k],y=w*A[k+i];
					A[k]=x+y; A[k+i]=x-y;
				}
			}
		}
		if(f<0){
			for(int i=0;i<n;i++) A[i].x=(ll)(A[i].x/n+0.5);
		}
	}
	void getmul(){
		FFT(A1,n,1),FFT(A2,n,1),FFT(B1,n,1),FFT(B2,n,1);
		for(int i=0;i<n;i++){
			C1[i]=A1[i]*B1[i];
			C2[i]=A1[i]*B2[i]+A2[i]*B1[i];
			C3[i]=A2[i]*B2[i];
		}
		FFT(C1,n,-1),FFT(C2,n,-1),FFT(C3,n,-1);
	}
	vector<ll> mul(vector<ll> a,vector<ll> b){
		n=1,l=0;
		while(n<a.size()+b.size()) n<<=1,l++;
		for(int i=0;i<n;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
		for(int i=0;i<n;i++) A1[i]=A2[i]=B1[i]=B2[i]=node(0,0);
		for(int i=0;i<a.size();i++){
			A1[i]=node(a[i]/tcys,0);
			A2[i]=node(a[i]%tcys,0);
		}
		for(int i=0;i<b.size();i++){
			B1[i]=node(b[i]/tcys,0);
			B2[i]=node(b[i]%tcys,0);
		}
		getmul();
		vector<ll> ret(k+1);
		for(int i=0;i<ret.size();i++) ret[i]=((ll)C1[i].x%cys*tcys*tcys%cys+(ll)C2[i].x%cys*tcys%cys+(ll)C3[i].x%cys)%cys;
		return ret;
	}
}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint(); k=readint();
	if(n>k) return printf("0\n"),0;
	fac[0]=inv[0]=1;
	for(int i=1;i<=k;i++) fac[i]=fac[i-1]*i%cys;
	inv[k]=qpow(fac[k],cys-2);
	for(int i=k-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	pl[0].push_back(0);
	for(int i=1;i<=k;i++) pl[0].push_back(inv[i]);
	for(int i=1;i<=16;i++){
		tmp=pl[i-1];
		for(int j=1;j<=k;j++) tmp[j]=tmp[j]*qpow(2,j*(1ll<<(i-1)))%cys;
		pl[i]=MTT::mul(tmp,pl[i-1]);
	}
	vector<ll> ans(0);
	ans.push_back(1);
	for(int i=1;i<=k;i++) ans.push_back(0);
	for(int i=16;i>=0;i--){
		if(n&(1<<i)){
			for(int j=1;j<=k;j++) ans[j]=ans[j]*qpow(2,j*(1ll<<i))%cys;
			ans=MTT::mul(ans,pl[i]);
		}
	}
	ll res=0;
	for(int i=1;i<=k;i++) res=(res+fac[k]*inv[k-i]%cys*ans[i])%cys;
	printf("%lld\n",res);
	return 0;
}