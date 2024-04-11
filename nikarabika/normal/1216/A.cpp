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
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 1; i < n; i+=2)
		if (s[i] == s[i - 1]) {
			s[i] ^= 'a' ^ 'b';
			ans++;
		}
	cout << ans << endl
		<< s << endl;
	return 0;
}