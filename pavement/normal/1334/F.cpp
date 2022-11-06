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

int N, M, R = 1e16, A[2000005], P[2000005], B[2000005], dp[2000005], ft[2000005], ft2[2000005];
map<int, vector<int> > pos;
pair<int, int> srt[2000005];

inline int ls(int x) { return x & -x; }

int qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft[p];
	return r;
}

void upd(int p, int v) {
	for (; p <= N; p += ls(p)) ft[p] += v;
}

int qry2(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft2[p];
	return r;
}

void upd2(int p, int v) {
	for (; p <= N; p += ls(p)) ft2[p] += v;	
}

main() {
	fill(dp, dp + 2000005, 1e16);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		srt[i] = mp(A[i], i);
		pos[A[i]].pb(i);
	}
	sort(srt + 1, srt + 1 + N, greater<pair<int, int> >());
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
		if (P[i] < 0) upd2(i, P[i]);
		P[i] += P[i - 1];
	}
	int tcur = 1;
	cin >> M;
	for (int i = 1; i <= M; i++) cin >> B[i];
	for (int i = M; i >= 1; i--) {
		while (tcur <= N && srt[tcur].first > B[i]) {
			upd(srt[tcur].second, P[srt[tcur].second] - P[srt[tcur].second - 1]);
			if (P[srt[tcur].second] - P[srt[tcur].second - 1] < 0) upd2(srt[tcur].second, -P[srt[tcur].second] + P[srt[tcur].second - 1]);
			tcur++;
		}
		if (i == M) for (int j : pos[B[i]]) dp[j] = qry(N) - qry(j) + qry2(N) - qry2(j);
		else {
			if (pos[B[i + 1]].size() == 0) continue;
			int idx = pos[B[i + 1]].size() - 1, msf = 1e16;
			for (int j = pos[B[i]].size() - 1; j >= 0; j--) {
				int cur = pos[B[i]][j];
				while (idx >= 0 && pos[B[i + 1]][idx] >= cur) {
					if (dp[pos[B[i + 1]][idx]] < 1e16) msf = min(msf, dp[pos[B[i + 1]][idx]] + qry(pos[B[i + 1]][idx] - 1) + qry2(pos[B[i + 1]][idx] - 1));
					idx--;
				}
				if (msf != 1e16) dp[cur] = msf - qry(cur) - qry2(cur);
			}
		}
	}
	for (int i = 1; i <= N; i++)
		if (A[i] == B[1] && dp[i] != 1e16) R = min(R, dp[i] + P[i - 1]);
	if (R > 5e5 * 1e9) cout << "NO\n";
	else cout << "YES\n" << R << '\n';
}