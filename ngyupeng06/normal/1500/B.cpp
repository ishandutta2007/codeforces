#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll mul_inv(ll a, ll b) { 
	ll b0 = b, t, q, x0 = 0, x1 = 1; 
	if (b == 1) return 1; 
	while (a > 1) { 
		q = a / b; 
		t = b; 
		b = a % b; 
		a = t; 
		t = x0;
		x0 = x1 - q * x0; 
		x1 = t; 
	} 
	if (x1 < 0) x1 += b0; 
	return x1; 
}

ll crt(ll a, ll x, ll b, ll y){
	ll d = __gcd(x,y);
	if (a % d != b % d) return -1;
	if (a > b){
		swap(a,b);
		swap(x,y);
	}
	ll p = x/d, q = y/d;
	ll t = ((b-a)/d * mul_inv(p, q) ) % q;
	return d * p * t + a;
}

ll n, m, k, a[500005], b[500005], rv[1000005];
bool vis[1000005];
vector<pll> v;
vector<ll> v1;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	ll d = __gcd(n,m);
	ll l = n * m / d;
	for (int i=0; i<n; i++){
		cin >> a[i];
		rv[a[i]] = i;
		vis[a[i]] = true;
	}
	for (int i=0; i<m; i++){
		cin >> b[i];
		if (vis[b[i]]){
			v.pb(mp(rv[b[i]], i));
		}
	}
	for (auto it: v){
		ll thing = crt(it.first, n, it.second, m);
		if (thing != -1) v1.pb(thing);
	}
	sort(v1.begin(), v1.end());
	ll sum = l - v1.size();
	ll alot = (k-1)/sum;
	ll left = k - sum * alot;
	bool gd = false;
	for (ll i=0; i<v1.size(); i++){
		ll idx = v1[i];
		if (left > idx - i) continue;
		if (!gd) cout << alot * l + left + i;
		gd = true;
	}
	ll bruh = v1.size();
	if (!gd) cout << alot * l + left + bruh;
}