#include <iostream>
typedef long long ll;
using namespace std;

ll g(ll x){
	ll res = 1;
	for(int i = 0; i < x; i++){
		res *= 4;
	}
	res -= 1;
	res /= 3;
	return res; // (4 ** x - 1) / 3;
}

void f(ll n, ll k){
	ll _min = 0;
	while(g(_min) + 1 < k){
		_min++;
	}
	if(_min <= n - 1){
		cout << "YES" << ' ' << n - 1 << endl;
	}else if(_min == n){
		ll UB = 0;
		ll LB = 0;
		for(int i = n - 1; i >= 0; i--){
			UB += (1LL << (n - i)) - 1 + g(i) * ((1LL << (n - i + 1)) - 3);
			LB += (1LL << (n - i)) - 1;
			if(UB >= k && k >= LB){
				cout << "YES" << ' ' << i << endl;
				return;
			}
		}
		cout << "NO" << endl;
	}else{
		cout << "NO" << endl;
	}
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		f(n, k);
	}
	return 0;
}