#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> arr(n);
	for (auto &i : arr) cin >> i;
	set<int> curr;
	for (int i = 0; i < q; ++i) {
		int mode, v;
		cin >> mode >> v, --v;
		if (mode == 1) {
			curr.insert(arr[v]);
			if (curr.size() > k) curr.erase(curr.begin());
		} else {
			if (curr.count(arr[v])) cout << "YES\n";
			else cout << "NO\n";
		}
	}
    return 0;
}