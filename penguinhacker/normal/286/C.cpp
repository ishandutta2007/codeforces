#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, m, p[mxN];
bool neg[mxN];
vector<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> p[i];
	}
	cin >> m;
	for (int i=0; i<m; ++i) {
		int x; cin >> x, --x;
		neg[x]=1;
	}
	s.reserve(mxN);
	for (int i=n-1; ~i; --i) {
		if (s.empty()||neg[i]||p[i]!=s.back()) {
			s.push_back(p[i]);
			p[i]=-p[i];
		}
		else {
			s.pop_back();
		}
	}
	if (!s.empty()) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for (int i=0; i<n; ++i) {
		cout << p[i] << " ";
	}
	return 0;
}