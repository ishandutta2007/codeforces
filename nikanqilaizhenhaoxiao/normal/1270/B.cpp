#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<pair<int, int> > a(n);
		vector<pair<int, int> > b;
		for (int i = 0; i < n; ++i) {
			cin >> a[i].first;
			a[i].second = i + 1;
			if(i > 0) {
				if(abs(a[i].first - a[i - 1].first) >= 2) b.push_back(make_pair(i, i + 1));
			}
		}
		if(b.size()) {
			cout << "YES\n";
			cout << b[0].first << ' ' << b[0].second << endl;
		}
		else cout << "NO\n";
	}
	return 0;
}