#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int BLK_SZ = 400;
int N, M, t, a, b, o1, o2, idx[100005], out[100005], bk[100005], power[100005];
vector<int> blk[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		if ((i - 1) % BLK_SZ == 0) idx[i] = idx[i - 1] + 1;
		else idx[i] = idx[i - 1];
		blk[idx[i]].pb(i);
	}
	for (int i = 1; i <= N; i++) cin >> power[i];
	for (int i = 1; i <= N; i++) {
		for (int j = (int)blk[i].size() - 1; j >= 0; j--) {
			int k = blk[i][j];
			if (k + power[k] > blk[i].back()) {
				out[k] = 1;
				bk[k] = k;
			} else {
				out[k] = out[power[k] + k] + 1;
				bk[k] = bk[power[k] + k];
			}
		}
	}
	while (M--) {
		cin >> t;
		if (t == 0) {
			cin >> a >> b;
			power[a] = b;
			for (int j = blk[idx[a]].size() - 1; j >= 0; j--) {
				int k = blk[idx[a]][j];
				if (power[k] + k > blk[idx[a]].back()) {
					out[k] = 1;
					bk[k] = k;
				} else {
					out[k] = out[power[k] + k] + 1;
					bk[k] = bk[power[k] + k];
				}
			}
		} else {
			cin >> a;
			int curr = a, o1 = -1, o2 = 0;
			while (1) {
				if (power[bk[curr]] + bk[curr] > N) {
					o1 = bk[curr];
					o2 += out[curr];
					break;
				} else {
					o2 += out[curr];
					curr = bk[curr] + power[bk[curr]];
				}
			}
			cout << o1 << ' ' << o2 << '\n';
		}
	}
}