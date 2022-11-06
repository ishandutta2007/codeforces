#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int ask(int k1, int k2, std::vector<int>& v1, std::vector<int>& v2) {
	cout << k1 << " " << k2 << " ";
	for (int i = 0; i < k1; ++i) {
		cout << v1[i] << " ";
	}
	for (int i = 0; i < k2; ++i) {
		cout << v2[i] << " ";
	}
	cout << endl;
	int x; cin >> x;
	if (x == -1) {
		cerr << "Error :" << endl;
		exit(1);
	}
	return x;
}

void give(int y) {
	cout << "-1 " << y << endl;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int t; cin >> t;
	srand(time(NULL));
	while (t--) {
		int n; cin >> n;
		int rr = 0;
		for (int i = 0; i < 9; ++i) {
			std::vector<int> v1;
			std::vector<int> v2;
			for (int j = 1; j <= n; ++j) {
				if (j & (1 << i))
					v1.pb(j);
				else 
					v2.pb(j);
			}
			if (!v1.empty() && !v2.empty()) {
				int r = ask(v1.size(), v2.size(), v1, v2);
				rr = max(r, rr);
			} 
		}
		give(rr);
	}
}