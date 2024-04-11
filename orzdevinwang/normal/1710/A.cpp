#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
ll n, m, k, a[N];
bool check() {
	ll sum = 0;
	bool ok = false;
	L(i, 1, k) {
		ll t = a[i] / n; 
		if(t >= 2) {
			if(t > 2) ok = true;
			sum += t;
		}
	} 
	if(sum < m) return false;
	if(sum % 2 == m % 2) ok = true;
	return ok;
}
void Main() {
	cin >> n >> m >> k;
	L(i, 1, k) cin >> a[i];
	if(check()) return cout << "Yes\n", void();
	swap(n, m);
	if(check()) return cout << "Yes\n", void();
	cout << "No\n";
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);  
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}