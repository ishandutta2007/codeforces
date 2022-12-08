#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;
typedef long double ld;

using namespace std;

const int dd = (int)2e6 + 7;

int A[dd], cnt[dd];
ll tmp[dd];
pair<int, int> msk[20];
int count2[20], w;
ll pw[20];
ll ans = 0;

void get(int i, ll k) {
	if (i == w) {
		ans += tmp[k];
		return;
	}
	if (count2[i] == 1) {
		get(i + 1, k + pw[i] * msk[i].first);
		return;
	}
	get(i + 1, k + pw[i] * msk[i].first);
	get(i + 1, k + pw[i] * msk[i].second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> w >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
		cnt[A[i]]++;
	}

	pw[0] = 1;
	for (int i = 1; i <= w; ++i) {
		pw[i] = pw[i - 1] * 3;
	}

	for (int i = 0; i < (1 << w); ++i) if (cnt[i]) {
		for (int j = 0; j < (1 << w); ++j) if (cnt[j]) {
			int k = 0;
			for (int l = 0; l < w; ++l) {
				int ii = (i >> l) & 1, jj = (j >> l) & 1;
				if (ii == jj && ii == 1) {
					k += 2 * pw[l];
				}
				if (ii != jj) {
					k += pw[l];
				}
			}
			tmp[k] += cnt[i] * cnt[j];
		}
	}

	while (m--) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		for (int i = 0; i < w; ++i) {
			if (s[i] == 'A') msk[i] = { 0, 1 }, count2[i] = 2;
			if (s[i] == 'O') msk[i] = { 0, 0 }, count2[i] = 1;
			if (s[i] == 'X') msk[i] = { 0, 2 }, count2[i] = 2;
			if (s[i] == 'a') msk[i] = { 2, 2 }, count2[i] = 1;
			if (s[i] == 'o') msk[i] = { 1, 2 }, count2[i] = 2;
			if (s[i] == 'x') msk[i] = { 1, 1 }, count2[i] = 1;
		}
		ans = 0;
		get(0, 0);
		cout << ans << "\n";
	}
	return 0;
}