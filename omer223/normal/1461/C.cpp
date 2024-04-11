#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e5;
int n, m;
int a[sz];
pair<int, ld> p[sz];

void input() {
	cin >> n >> m;
	foru(i, 0, n)cin >> a[i];
	foru(i, 0, m)cin >> p[i].first >> p[i].second;
}

void solve() {
	input();
	int so = n;
	ford(i, n - 1, 0) {
		if (a[i] == i + 1)so--;
		else break;
	}
	ld probnot = 1;
	foru(i, 0, m) {
		if (p[i].first >= so)probnot *= (1 - p[i].second);
	}
	if(so!=0)cout << fixed<<setprecision(10)<<1 - probnot << '\n';
	else cout << 1 << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}