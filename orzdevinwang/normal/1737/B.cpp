#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
using namespace std;
const int N = 1 << 20;
ll l, r;
ll calc(ll x) {
	ll u = max(sqrt(x) - 2, 0.), ns = 0;
	while((u + 1) * (u + 1) <= x) ++u;
	ns += u;
	u = max(sqrt(x) - 2, 0.);
	while((u + 1) * (u + 2) <= x) ++u;
	ns += u;
	u = max(sqrt(x) - 2, 0.);
	while((u + 1) * (u + 3) <= x) ++u;
	ns += u;
	return ns;
}
void Main() {
	cin >> l >> r;
	cout << calc(r) - calc(l - 1) << '\n';
} 
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}