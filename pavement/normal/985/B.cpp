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

int N, M;
map<int, vector<int> > cnt;
char A[2005][2005];
bool hv[2005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
			if (A[i][j] - '0') {
				cnt[j].pb(i);
			}
		}
	for (auto i : cnt) {
		if (i.second.size() == 1) hv[i.second[0]] = 1;
	}
	for (int i = 1; i <= N; i++)
		if (!hv[i]) return cout << "YES\n", 0;
	cout << "NO\n";
}