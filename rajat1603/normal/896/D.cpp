#include "bits/stdc++.h"
using namespace std;
void extended(int a , int b , long long &x , long long &y){
	if(b == 0){
		x = 1;
		y = 0;
		return;
	}
	extended(b , a % b , x , y);
	x = x - 1LL * (int(a / b)) * y;
	swap(x , y);
}
pair < long long , long long > get(int a , int b){
	bool swapped = 0;
	if(a < b){
		swap(a , b);
		swapped = 1;
	}
	long long x , y;
	extended(a , b , x , y);
	if(swapped){
		swap(x , y);
		swap(a , b);
	}
	return {x , y};
}
int inverse(int x , int mod){
	x %= mod;
	if(x < 0){
		x += mod;
	}
	long long res = get(x , mod).first;
	res %= mod;
	res += mod;
	res %= mod;
	return res;
}
const int N = 1e5 + 5;
int n , mod , l , r;
int fact[N];
int inv[N];
int getp(int n , int p){
	int res = 0;
	while(n >= p){
		n /= p;
		res += n;
	}
	return res;
}
vector < int > primes;
int ncr(int n , int r){
	if(r > n){
		return 0;
	}
	int res = 1;
	res = (1LL * res * fact[n]) % mod;
	res = (1LL * res * inv[r]) % mod;
	res = (1LL * res * inv[n - r]) % mod;
	for(int p : primes){
		int pw = 0;
		pw += getp(n , p);
		pw -= getp(r , p);
		pw -= getp(n - r , p);
		for(int i = 0 ; i < pw ; ++i){
			res = (1LL * res * p) % mod;
		}
	}
	return res;
}
int solve(){
	long long ans = 0;
	for(int i = 0 ; i <= n ; ++i){
		long long res = 0;
		res -= ncr(i , (i + r + 2) >> 1);
		res += ncr(i , (i + l + 1) >> 1);
		res %= mod;
		res += mod;
		res %= mod;
		res = (1LL * res * ncr(n , i)) % mod;
		ans += res;
		ans %= mod;
	}
	return ans;
}
int main(){
	cin >> n >> mod >> l >> r;
	fact[0] = 1;
	inv[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		int val = i;
		while(__gcd(val , mod) != 1){
			val /= __gcd(val , mod);
		}
		fact[i] = (1LL * fact[i - 1] * val) % mod;
		inv[i] = (1LL * inv[i - 1] * inverse(val , mod)) % mod;
	}
	int tmp = mod;
	for(int i = 2 ; i * i <= tmp ; ++i){
		if(tmp % i == 0){
			while(tmp % i == 0){
				tmp /= i;
			}
			primes.emplace_back(i);
		}
	}
	if(tmp > 1){
		primes.emplace_back(tmp);
	}
	printf("%d\n" , solve());
}