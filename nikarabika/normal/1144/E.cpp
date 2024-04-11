//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	string s, t;
	cin >> n
		>> s
		>> t;

	int a[n],
	b[n],
	c[n + 1];
	reverse(all(s));
	reverse(all(t));
	for (int i = 0; i < n; i++)
		a[i] = s[i] - 'a', b[i] = t[i] - 'a';
	memset(c, 0, sizeof c);
	for (int i = 0; i < n; i++) {
		c[i] += a[i] + b[i];
		c[i + 1] += c[i] / 26;
		c[i] %= 26;
	}
	int rem = 0;
	for (int i = n; i >= 0; i--) {
		int nw = (c[i] + rem) / 2;
		rem = ((c[i] + rem) % 2) * 26;
		c[i] = nw;
	}
	string ans;
	for (int i = 0; i < n; i++)
		ans += 'a' + c[i];
	reverse(all(ans));
	cout << ans << endl;
	
	return 0;
}