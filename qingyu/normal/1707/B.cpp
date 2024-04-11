#include <bits/stdc++.h>

using namespace std; // i don't like it anyway...

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		map<int, int> A;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			++A[a[i]];
		}
		for (int i = 1; i < n; ++i) {
			map<int, int> b;
			int lst = 0;
			bool is_first = true;
			for (auto [x, count] : A) {
				if (count > 1)
					b[0] += count - 1;
				if (!is_first) {
					++b[x - lst];
				}
				lst = x;
				is_first = false;
			}
			A = b;
		}
		assert(A.size() == 1);
		auto it = *A.begin();
		cout << it.first << '\n';
	}
}