#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<string>
using namespace std;
int a[26];
int b[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) {
		string h, p;
		cin >> h >> p;
		for (int i = 0; i < 26; ++i)a[i]=b[i] = 0;
		bool ans = false;
		int lenh = h.length(), lenp = p.length();
		if (lenh > lenp) {
			cout << "NO\n";
			continue;
		}
		for (int i = 0; i < lenh; ++i)++a[h[i] - 'a'];
		for (int i = 0; i < lenh-1; ++i)++b[p[i] - 'a'];
		for (int i1 = 0, i = lenh - 1; i < lenp; ++i, ++i1) {
			bool tmp = true;
			++b[p[i] - 'a'];
			for (int j1 = 0; j1 < 26; ++j1)if (b[j1] != a[j1])tmp = false;
			if (tmp) {
				ans = true;
			}
			--b[p[i1] - 'a'];
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}