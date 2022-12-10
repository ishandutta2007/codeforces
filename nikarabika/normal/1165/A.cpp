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
	string s;
	int n, x, y;
	cin >> n >> x >> y;
	cin >> s;
	reverse(all(s));
	int ans = 0;
	for (int i = 0; i < x; i++)
		if (i == y)
			ans += s[i] == '0';
		else
			ans += s[i] == '1';
	cout << ans << endl;
	return 0;
}