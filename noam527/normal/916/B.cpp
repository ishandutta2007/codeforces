#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
using namespace std;

ll x;
int k, a[82] = {}, c;

int main() {
	ios::sync_with_stdio(0);
	cin >> x >> k;
	for (int i = 0; i < 62; i++)
		if (x & (1LL << i)) a[i + 20]++, k--;
	if (k < 0) finish("No");

	cout << "Yes" << endl;
	for (int i = 81; i > 0 && k >= a[i]; i--)
		k -= a[i], a[i - 1] += 2 * a[i], a[i] = 0;

	vector<int> ans;
	for (int i = 81; i >= 0; i--) for (int j = 0; j < a[i]; j++) ans.push_back(i);
	while (k--) {
		c = ans.back(), ans.pop_back();
		ans.push_back(c - 1), ans.push_back(c - 1);
	}
	for (auto &i : ans) cout << i - 20 << " "; cout << endl;
}