// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=1000000,cys=998244353;
int n,tot;
int prm[1000005],phi[1000005],a[1000005];
ll fac[1000005],inv[1000005];
bool fl[1000005];

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void getprime(){
	fl[1]=1;
	phi[1]=1;
	for(int i=2;i<=N;i++){
		if(!fl[i]) prm[++tot]=i,phi[i]=i-1;
		for(int j=1;j<=tot&&i*prm[j]<=N;j++){
			fl[i*prm[j]]=1;
			if(i%prm[j]==0){
				phi[i*prm[j]]=phi[i]*prm[j];
				break;
			}
			phi[i*prm[j]]=phi[i]*(prm[j]-1);
		}
	}
}

int main(){
	fac[0]=inv[0]=1;
	for(int i=1;i<=N;i++) fac[i]=fac[i-1]*i%cys;
	inv[N]=qpow(fac[N],cys-2);
	for(int i=N-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	getprime();
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=0;
		for(int i=1;i<=n;i++) a[readint()]++;
		int pl=0;
		for(int i=1;i<=n;i++) if(a[i]) pl=i;
		if(a[pl]==n){
			printf("1\n");
			continue;
		}
		int g=0;
		for(int i=1;i<=n;i++) g=__gcd(g,a[i]);
		vector<int> vec(0);
		for(int i=1;i<=n;i++) if(a[i]) vec.pb(i);
		ll ans2=0;
		for(int i=1;i<=g;i++){
			if(g%i) continue;
			ll tmp=fac[n/i-1]*inv[a[pl]/i-1]%cys;
			for(auto r:vec) if(r!=pl) tmp=tmp*inv[a[r]/i]%cys;
			ans2=(ans2+tmp*phi[i])%cys;
		}
		ll ans1=0;
		for(int i=1;i<=g;i++){
			if(g%i) continue;
			ll tmp=fac[n/i-1]*inv[a[pl]/i-1]%cys;
			for(auto r:vec) if(r!=pl) tmp=tmp*inv[a[r]/i]%cys;
			tmp=tmp*qpow(n/i-1,cys-2)%cys;
			ll res=0;
			for(auto r:vec) if(r!=pl) res=(res+2ll*tmp*(a[r]/i))%cys;
			ans1=(ans1+res*phi[i]%cys*i)%cys;
			if(n/i==2) continue;
			res=tmp*(n/i-1)%cys;
			tmp=tmp*qpow(n/i-2,cys-2)%cys;
			for(auto r:vec){
				if(r==pl){
					if(a[r]/i>=3) res=(res+cys-tmp*(a[r]/i-1)%cys*(a[r]/i-2)%cys)%cys;
				}
				else{
					if(a[r]/i>=2) res=(res+cys-tmp*(a[r]/i)%cys*(a[r]/i-1)%cys)%cys;
				}
			}
			ans1=(ans1+(n/i-2)*res%cys*phi[i]%cys*i)%cys;
		}
		printf("%lld\n",ans1*qpow(ans2,cys-2)%cys);
	}
	return 0;
}