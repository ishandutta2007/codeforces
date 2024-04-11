#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	ll n, ans, loc = 0;
	cin >> n, ans = n;
	vector<int> a(n);
	vector<set<int>> s(100001);
	for (int i = 0; i < n; i++) cin >> a[i], s[a[i]].insert(i);
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		set<int>::iterator it = s[a[i]].lower_bound(loc);
		if (it == s[a[i]].end())
			ans += n - i, loc = 0, it = s[a[i]].lower_bound(loc);
		loc = *it, s[a[i]].erase(it);
	}
	cout << ans << endl;
}