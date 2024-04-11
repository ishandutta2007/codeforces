#include <bits/stdc++.h>
#define m 1000000007
typedef long long ll;
using namespace std;

template <class T>
T powmod(T a, ll b){
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

int main(){
	int n, _m;
	cin >> n >> _m;
	cout << powmod<ll>(powmod<ll>(2, _m) - 1, n);
}