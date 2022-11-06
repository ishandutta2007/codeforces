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

int N, A[105];
vector<pair<int, int> > ins;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		int mpos = -1, mval = LLONG_MAX;
		for (int j = i; j <= N; j++)
			if (A[j] < mval) {
				mval = A[j];
				mpos = j;
			}
		for (int j = mpos; j > i; j--) {
			swap(A[j - 1], A[j]);
			ins.eb(j - 1, j);
		}
	}
	for (auto i : ins) cout << i.first << ' ' << i.second << '\n';
}