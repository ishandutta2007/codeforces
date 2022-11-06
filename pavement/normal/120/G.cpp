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

int N, T, M, tk, A[105][2], B[105][2], D[105][105], C[105];
vector<int> sc[105];
deque<int> dq;
string W[105];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> N >> T;
	for (int i = 1; i <= N; i++)
		cin >> A[i][0] >> B[i][0] >> A[i][1] >> B[i][1];
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> W[i] >> C[i];
		dq.pb(i);
	}
	while (!dq.empty())
		for (int j = 0; j <= 1; j++) {
			if (dq.empty()) break;
			for (int i = 1; i <= N; i++) {
				if (dq.empty()) break;
				for (int ct = T; !dq.empty() && ct; ) {
					int x = max(1ll, C[dq.front()] - (A[i][j] + B[i][!j]) - D[i][dq.front()]);
					if (x <= ct) {
						sc[i].pb(dq.front());
						dq.ppf();
						ct -= x;
					} else {
						D[i][dq.front()] += min(ct, x);
						dq.pb(dq.front());
						dq.ppf();
						break;
					}
				}
			}
		}
	for (int i = 1; i <= N; i++) {
		cout << sc[i].size();
		for (int j : sc[i])
			cout << ' ' << W[j];
		cout << '\n';
	}
}