#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	// cout << fixed << setprecision(12);
	
	int n, m;
	cin >> n >> m;
	map<string, string> a;
	string s1, s2;
	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2;
		a[s2] = s1;
	}
	for (int i = 0; i < m; i++) {
		cin >> s1 >> s2;
		cout << s1 << " " << s2 << " #";
		s2.pop_back();
		cout << a[s2] << "\n";
	}
	
	return 0;
}