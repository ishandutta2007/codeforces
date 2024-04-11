#include <stdio.h>
#include <map>
#include <vector>
#define MN 1000000

using std::map;
using std::vector;

using ll = long long;

const int mod = 998244353;

int qpow(int bsc,int y){
	int ret = 1;
	while(y){
		if(y&1) ret = (ll)ret*bsc%mod;
		bsc = (ll)bsc*bsc%mod;
		y >>= 1;
	}
	return ret;
}

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

namespace Math{
	bool notPrime[MN+5];
	vector<int> primes;
	int phi[MN+5];
	
	void initPrimes(int n){
		phi[1] = 1;
		for(int i=2;i<=n;i++){
			if(!notPrime[i]){
				primes.push_back(i);
				phi[i] = i-1;
			}
			for(int p:primes){
				if(i*p>n) break;
				notPrime[i*p] = true;
				if(i%p==0){
					phi[i*p] = phi[i]*p;
					break;
				}else{
					phi[i*p] = phi[i]*(p-1);
				}
			}
		}
	}
	
	int fac[MN+5],inv[MN+5];
	
	void initCombines(int n){
		fac[0] = 1;
		for(int i=1;i<=n;i++){
			fac[i] = (ll)fac[i-1]*i%mod;
		}
		inv[n] = qpow(fac[n],mod-2);
		for(int i=n-1;i>=0;i--){
			inv[i] = (ll)inv[i+1]*(i+1)%mod;
		}
	}
	
	int C(int n,int m){
		if(n<0||m<0||n<m) return 0;
		return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;
	}
	
	void init(int n){
		initPrimes(n);
		initCombines(n);
	}
	
};

using Math::phi;
using Math::fac,Math::inv,Math::C;

int n;
map<int,int> cnt;

struct CountResult{
	int bdg,way;
};

CountResult count(int gcnt){
	int d = n/gcnt;
	int ans = 0;
	int tot = fac[d];
	for(auto p:cnt){
		int c = p.second/gcnt;
		tot = (ll)tot*inv[c]%mod;
		if(c==1) continue;
		ans = (ans+(ll)C(d-2,c-2)*qpow(C(d,c),mod-2))%mod;
	}
	ans = (ll)ans*d%mod;
	ans = (ll)ans*tot%mod;
	ans = (ll)ans*gcnt%mod;
	return {ans,tot};
}

void solve(){
	cnt.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	if(cnt.size()==1){
		puts("1");
	}else{
		int g = 0;
		for(auto p:cnt){
			g = gcd(g,p.second);
		}
		int ans = 0;
		int tot = 0;
		for(int i=1;i<=g;i++){
			if(g%i) continue;
			CountResult result = count(i);
			ans = (ans+(ll)phi[i]*result.bdg)%mod;
			tot = (tot+(ll)phi[i]*result.way)%mod;
		}
		ans = (ll)ans*qpow(tot,mod-2)%mod;
		ans = (n-ans+mod)%mod;
		printf("%d\n",ans);
	}
}

int main(){
	Math::init(MN);
	int T;
	scanf("%d",&T);
	while(T--) solve();
}