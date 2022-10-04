#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#define mp make_pair

using namespace std;
typedef pair<int, int> pii;

const int B = 262144;

struct BIT {
	int tr[2 * B];
	int modified[2 * B];
	int mod_val[2 * B];
	void push(int nd) {
		if (!modified[nd]) return;
		tr[nd] = max(tr[nd], mod_val[nd]);
		int mv = mod_val[nd];
		mod_val[nd] = modified[nd] = 0;
		if (nd >= B) return;
		mod_val[2 * nd] = max(mod_val[2 * nd], mv);
		mod_val[2 * nd + 1] = max(mod_val[2 * nd + 1], mv);
		modified[2 * nd] = modified[2 * nd + 1] = 1;
		return;
	}
	void upd(int nd, int ndl, int ndr, int l, int r, int val) {
		if (l > r || ndl > r || l > ndr) return;
		else if (l <= ndl && ndr <= r) {
			modified[nd] = 1;
			mod_val[nd] = max(mod_val[nd], val);
			return;
		}
		else {
			tr[nd] = max(tr[nd], val);
			int mid = (ndl + ndr) / 2;
			upd(2 * nd, ndl, mid, l, r, val);
			upd(2 * nd + 1, mid + 1, ndr, l, r, val);
		}
	}
	void update_node(int nd) {
		if (nd > 1) update_node(nd / 2);
		push(nd);
	}
	int get(int i) {
		update_node(B + i);
		return tr[B + i];
	}
}R, C;

set<int> Upos;
map<int, int> Uind;
set<int> Lpos;
map<int, int> Lind;
pair<pii, char> query[B];
int zeroq[B];

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; i++) {
		int x, y; char tp;
		scanf("%d %d %c", &x, &y, &tp);
		query[i] = mp(mp(x, y), tp);
		if (tp == 'U') {
			if (Upos.find(x) != Upos.end()) {
				zeroq[i] = 1;
				continue;
			}
			Upos.insert(x);
		}
		else {
			if (Lpos.find(y) != Lpos.end()) {
				zeroq[i] = 1;
				continue;
			}
			Lpos.insert(y);
		}
	}
	Upos.insert(0); Lpos.insert(0);
	int i = 0;
	for (auto &x : Upos) {
		Uind[x] = i;
		i++;
	}
	i = 0;
	for (auto &x : Lpos) {
		Lind[x] = i;
		i++;
	}
	for (int i = 0; i < q; i++) {
		if (zeroq[i]) {
			puts("0"); continue;
		}
		int x = query[i].first.first;
		int y = query[i].first.second;
		if (query[i].second == 'U') {
			int M = C.get(Uind[x]);
			printf("%d\n", y - M);
			auto it = Lind.upper_bound(y);
			if (it == Lind.begin()) continue;
			it--;
			R.upd(1, 0, B - 1, Lind[M], it->second, x);
		}
		else {
			int M = R.get(Lind[y]);
			printf("%d\n", x - M);
			auto it = Uind.upper_bound(x);
			if (it == Uind.begin()) continue;
			it--;
			C.upd(1, 0, B - 1, Uind[M], it->second, y);
		}
	}

	return 0;
}