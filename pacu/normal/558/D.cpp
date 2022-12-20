#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MAXQ 100000

int H, Q;
int QNO = 0;
pair<LL, LL> LR[MAXQ];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> Q;
	LL lo = 1LL << (H - 1);
	LL hi = (lo << 1) - 1;
	for (int q = 0; q < Q; q++) {
		int i, ans;
		LL l, r;
		cin >> i >> l >> r >> ans;
		LL bl = l << (H - i);
		LL br = ((r + 1) << (H - i)) - 1;
		if (ans == 1) {
			lo = max(lo, bl);
			hi = min(hi, br);
		}
		else {
			LR[QNO] = make_pair(bl, br);
			QNO++;
		}
	}

	sort(LR, LR + QNO);
	LL ans = -1;
	for (int i = 0; i < QNO; i++) {
		if (lo > hi) {
			break;
		}
		pair<LL, LL> p = LR[i];
		LL L = p.first, R = p.second;
		if (L > lo) {
			if (min(hi+1-lo,L - lo) > 1 || ans != -1) {
				cout << "Data not sufficient!" << endl;
				return 0;
			}
			ans = lo;
		}
		lo = max(lo, R + 1);
	}

	if (lo > hi && ans == -1) {
		cout << "Game cheated!" << endl;
	}
	else if (lo > hi && ans != -1) {
		cout << ans << endl;
	}
	else if (ans == -1) {
		if (lo == hi) {
			cout << lo << endl;
		}
		else {
			cout << "Data not sufficient!" << endl;
		}
	}
	else {
		cout << "Data not sufficient!" << endl;
	}

	cout.flush();
	return 0;
}