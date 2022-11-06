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

int N;
string S[70005];
map<string, int> O;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		set<string> T;
		cin >> S[i];
		for (int j = 0; j < S[i].size(); j++) {
			string tmp = "";
			for (int k = j; k < S[i].size(); k++) {
				tmp.pb(S[i][k]);
				T.insert(tmp);
			}
		}
		for (auto j : T) O[j]++;
	}
	for (int i = 1; i <= N; i++) {
		int ans = 1e9;
		string res = "";
		for (int j = 0; j < S[i].size(); j++) {
			string tmp = "";
			for (int k = j; k < S[i].size(); k++) {
				tmp.pb(S[i][k]);
				if (O[tmp] == 1 && k - j + 1 < ans) {
					ans = k - j + 1;
					res = tmp;
					break;
				}
			}
		}
		cout << res << '\n';
	}
}