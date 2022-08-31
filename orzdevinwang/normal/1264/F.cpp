#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
ll t = 1.5e9, mod = 1e18, cm = 1e9;
void exgcd (ll a, ll b, ll &x, ll &y) {
	if(b == 0) 
		return x = 1, y = 0, void ();
	exgcd (b, a % b, y, x);
	y -= x * (a / b);
}
// r = 584177449000000001
ll rpw (ll x, ll mod) {
	ll a, b;
	exgcd (x, mod, a, b);
	return (a % mod + mod) % mod;
}
int main() {
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	ll iv = rpw (584177449, cm);
	ll n, a, d;
	cin >> n >> a >> d;
	cout << a * iv % cm * t + 1 << ' ' << d * iv % cm * t << '\n';
//	ll x = 0, y = 1;
//	L(i, 2, t) (x += y) %= mod, swap(x, y);
//	cout << y << ' ' << (x + y) % mod << '\n';
	
	return 0;
}