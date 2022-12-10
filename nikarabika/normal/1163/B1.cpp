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

multiset<int> s;
int n;
int cnt[100 * 100 * 100];

bool good() {
	if (sz(s) <= 1)
		return true;
	if (*s.begin() == 1) {
		auto it = s.begin();
		it++;
		if (*s.rbegin() == *it)
			return true;
	}
	if (*s.rbegin() - *s.begin() > 1)
		return false;
	auto it = s.end();
	it--;
	auto it2 = it;
	it2--;
	if (*it != *it2)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int ans = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (cnt[x])
			s.erase(s.lower_bound(cnt[x]));
		cnt[x]++;
		s.insert(cnt[x]);
		if (good())
			ans = i + 1;
	}
	cout << ans << endl;
	return 0;
}