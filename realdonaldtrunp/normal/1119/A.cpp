#include"bits/stdc++.h"
#include "chrono"
using namespace std;
typedef long long ll;

int n;

set<pair<int, int> > s;
map<int, int> ms;

int main() {
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (ms.count(a)) {

		}
		else {
			s.insert(make_pair(i, a));
			ms[a] = i;
		}
		for (auto it : s) {
			if (it.second == a) {
				continue;
			}
			ans = max(ans, i - it.first);
			break;
		}
	}
	cout << ans << endl;
	return 0;
}