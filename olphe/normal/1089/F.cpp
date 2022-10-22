#include "bits/stdc++.h"

using namespace std;
using ll = long long int;

// ax + by = gcd(a, b)  {x, y, gcd(a, b)} 
// O(log(min(a, b)))
ll extgcd(ll a, ll b, ll &x, ll &y) {
  ll g = a; x = 1, y = 0;
  if(b != 0) g = extgcd(b, a%b, y, x), y -= (a/b) * x;
  return g;
}

int main(){
	ll n;
	cin >> n;
		
	ll t = n;
	vector<ll> v;
	for(ll i=2; i*i<=t; ++i) {
		bool first = true;
		while(t%i==0) {
			if(first) v.push_back(i);
			first = false;
			t /= i;
		}	
	}
	if(t>1) v.push_back(t);
	if(v.size() <= 1) {
		cout << "NO" << endl;
		return 0;
	}
	
	// v[0] * x + v[1] * y = n-1
	cout << "YES" << endl;
	ll x, y;
	ll g = extgcd(v[0], v[1], x, y);
	x *= n-1, y *= n-1;
	if(x < 0) {
		ll k = (abs(x)+v[1]-1) / v[1];
		x+=k*v[1];
		y-=k*v[0];
	} else if(y < 0) {
		ll k = (abs(y)+v[0]-1) / v[0];
		y+=k*v[0];
		x-=k*v[1];
	}
	if(x < 0 || y < 0 || x * v[0] + y * v[1] != n-1) {
		cout << "NO" << endl;
		return 0;
	}
	cout << 2 << endl;
	cout << x << " " << n / v[0] << endl;
	cout << y << " " << n / v[1] << endl; 
	
	return 0;
}