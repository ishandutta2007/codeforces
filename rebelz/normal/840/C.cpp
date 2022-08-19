#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
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
int n;
ll a[305],d[305],f[305],fac[305],inv[305];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%cys;
	inv[n]=qpow(fac[n],cys-2);
	for(int i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	for(int i=1;i<=n;i++){
		int tmp=a[i]; a[i]=1;
		for(int j=2;j*j<=tmp;j++){
			if(tmp%j==0){
				int num=0;
				while(tmp%j==0) tmp/=j,num^=1;
				if(num&1) a[i]*=j;
			}
		}
		if(tmp>1) a[i]*=tmp;
	}
	sort(a+1,a+n+1);
	vector<int> v(0);
	int cur=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]) cur++;
		else v.pb(cur),cur=1;
	}
	v.pb(cur);
	d[0]=1;
	for(auto r:v){
		for(int i=0;i<=n;i++) f[i]=0;
		for(int i=0;i<=n;i++){
			if(!d[i]) continue;
			for(int j=1;j<=r;j++){
				ll tmp=fac[r]*fac[r-1]%cys*inv[j-1]%cys*inv[r-j]%cys*inv[j]%cys;
				if((r-j)&1) f[i+j]=mod(f[i+j]+cys-d[i]*tmp%cys);
				else f[i+j]=mod(f[i+j]+d[i]*tmp%cys);
			}
		}
		for(int i=0;i<=n;i++) d[i]=f[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans=(ans+fac[i]*d[i])%cys;
	printf("%lld\n",ans);
	return 0;
}