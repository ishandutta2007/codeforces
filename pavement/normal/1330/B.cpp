#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
typedef long double ld;

int T, M, N, A[200005], cnt[200005], B, C, X, Y, Z;
bool L[200005], R[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		memset(cnt, 0, sizeof cnt);
		memset(L, 0, sizeof L);
		memset(R, 0, sizeof R);
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> A[i];
		set<int> need;
		int cntabv = 0;
		for (int i = 1; i <= N; i++) {
			cnt[A[i]]++;
			if (need.find(A[i]) != need.end()) {
				need.erase(need.find(A[i]));
			}
			if (A[i] != 1 && !cnt[A[i] - 1]) need.insert(A[i] - 1);
			if (cnt[A[i]] > 1) cntabv++;
			if (cntabv || need.size()) L[i] = 0;
			else L[i] = 1;
		}
		need.clear();
		cntabv = 0;
		memset(cnt, 0, sizeof cnt);
		for (int i = N; i >= 1; i--) {
			cnt[A[i]]++;
			if (need.find(A[i]) != need.end()) need.erase(need.find(A[i]));
			if (A[i] != 1 && !cnt[A[i] - 1]) need.insert(A[i] - 1);
			if (cnt[A[i]] > 1) cntabv++;
			if (cntabv || need.size()) R[i] = 0;
			else R[i] = 1;
		}
		vector<pair<int, int> > V;
		for (int i = 1; i <= N; i++)
			if (L[i] && R[i + 1]) V.eb(i, N - i);
		cout << V.size() << '\n';
		for (auto i : V) cout << i.first << ' ' << i.second << '\n';
	}
}