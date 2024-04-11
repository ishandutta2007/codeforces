#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

const int N = 2e5 + 5;

int n, a[N], t[N];
string s;
vector<int> pos[26];
ll inv;

void srt(int l, int r) {
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	srt(l, mid);
	srt(mid + 1, r);

	copy(a + l, a + r + 1, t + l);
	for (int i = l, j = mid + 1, k = l; k <= r; k++) {
		if (i <= mid and j <= r) {
			if (t[i] < t[j]) {
				a[k] = t[i++];
			} else {
				a[k] = t[j++];
				inv += mid - i + 1;
			}
		} else if (i <= mid) {
			a[k] = t[i++];
		} else {
			a[k] = t[j++];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		pos[s[i] - 'a'].push_back(i);
	}
	for (int j = 0; j < 26; j++) {
		for (int i = 0, ii = (int)pos[j].size() - 1; i < pos[j].size(); i++, ii--) {
			a[pos[j][i]] = n - pos[j][ii] - 1;
		}
	}

	srt(0, n - 1);
	cout << inv << '\n';
	return 0;
}