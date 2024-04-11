#include <iostream>
#include <vector>

using namespace std;

int a[101010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		vector<int> v;
		v.push_back(a[1]);
		for (int i = 2; i <= n-1; i++) {
			if (a[i-1] < a[i] && a[i] < a[i+1]) continue;
			if (a[i-1] > a[i] && a[i] > a[i+1]) continue;
			v.push_back(a[i]);
		}
		v.push_back(a[n]);
		cout << v.size() << "\n";
		for (auto x : v) cout << x << " ";
		cout << "\n";
	}
}