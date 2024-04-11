#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

int N, K, T, A[100005], mat[100005];
bool V[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int pos = -1, pos1 = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.') pos1 = i;
		if (s[i] == 'e') {
			pos = i + 1;
			break;
		}
	}
	int u = stoi(s.substr(pos, s.size() - pos + 1));
	if (u == 0 && pos - pos1 - 2 == 1 && stoi(s.substr(pos1 + 1, pos - pos1 - 1)) == 0) {
		int a = stoi(s.substr(0, pos1));
		cout << a << '\n';
		return 0;
	}
	string occ = "";
	for (char c : s) {
		if (c == 'e') break;
		if (c != '.') occ.pb(c);
	}
	int pos2 = pos1 + u;
	for (int i = 0; i < occ.size(); i++) {
		if (i == pos2) cout << '.';
		cout << occ[i];
	}
	for (int i = occ.size(); i < pos2; i++)
		cout << '0';
	cout << '\n';
}