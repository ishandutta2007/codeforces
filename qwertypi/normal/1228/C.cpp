#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int m = 1000000007;
template <class T>
T powmod(T a, ll b, ll m){
	T res = 1;
	while(b){
		if(b % 2){
			res *= a;
			res %= m;
		}
		a = (a * a) % m;
		b /= 2;
	}
	return res;
}

ll f(ll n, ll k){
	ll res = 0;
	while(n){
		res += n / k;
		n /= k;
	}
	return powmod<ll>(k, res, m);
}

int main(){
	ll x, n;
	cin >> x >> n;
	vector<int> pf;
	if(x % 2 == 0){
		pf.push_back(2);
		while(x % 2 == 0){
			x /= 2;
		}
	}
	for(int i = 3; i * i <= x; i++){
		if(x % i == 0){
			while(x % i == 0){
				x /= i;
			}
			pf.push_back(i);
		}
	}
	if(x != 1){
		pf.push_back(x);
	}
	ll ans = 1;
	for(auto i : pf){
		ans = (ans * f(n, i)) % m;
	}
	cout << ans;
}