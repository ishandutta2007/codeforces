// sobskdrbhvk...
// remember... ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back

int main() {
	int n;
	cin >> n;
	int a[n],
	s[n + 1];
	s[0] = 0;
	map<int, int> mp[2];
	LL ans = 0;
	mp[1][s[0]]++;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s[i + 1] = s[i] ^ a[i];
		ans += mp[i & 1][s[i + 1]];
		mp[i & 1][s[i + 1]]++;
	}
	cout << ans << endl;
	return 0;
}