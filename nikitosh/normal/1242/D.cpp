#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using vi = vector<int>;
using pii = pair<int, int>;
 
#define FNAME ""

// 1..k^2+1
ll gett(ll n, ll k) {
	if (n == 0)
		return k * (k + 1) / 2;
	ll num = gett(n / k, k);
	ll t = n % k;
	ll i = (num - 1) / k;
	ll j = (num - 1) % k;
	ll res = k * (k + 1) / 2 - t;
	if (t > i)
		res += k;
	if (t == i)
		res += k - j;
	return res;
}

ll solve(ll n, ll k) {
	ll x = k * k + 1;
	ll ind = (n - 1) / x;
	ll num = gett(ind, k);
	ll rem = (n - 1) % x + 1;
	if (rem == num) {
		ll t = ind % k;
		ll i = ind / k;
		return k * (k + 1) * i + (t + 1) * (k + 1);	
	}
	if (rem >= num)
		rem--;
	return k * (k + 1) * ind + (rem - 1) / k * (k + 1) + (rem - 1) % k + 1; 
}
  
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int tn;
	cin >> tn;
	forn (tt, tn) {
		ll n, k;
		cin >> n >> k;
		cout << solve(n, k) << "\n";
	}	
	
	return 0;
}