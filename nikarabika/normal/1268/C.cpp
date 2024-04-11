//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1 << 18,
	  maxl = 18;
LL self[maxn];
int fen[maxn],
	pos[maxn],
	a[maxn],
	n;

struct SegmentTree {
	LL seg[maxn << 2];
	int laz[maxn << 2];
	
	void add(int st, int en, int val = 1, int l = 0, int r = n, int id = 1) {
		if (st >= r or en <= l)
			return;
		if (st <= l and r <= en) {
			seg[id] += 1LL * (r - l) * val;
			laz[id] += val;
			return;
		}
		int mid = (l + r) >> 1;
		add(st, en, val, l, mid, id << 1 | 0);
		add(st, en, val, mid, r, id << 1 | 1);
		seg[id] = seg[id << 1 | 0] + seg[id << 1 | 1] + 1LL * laz[id] * (r - l);
	}

	LL get(int st, int en, int l = 0, int r = n, int id = 1) {
		if (st >= r or en <= l)
			return 0;
		if (st <= l and r <= en)
			return seg[id];
		int mid = (l + r) >> 1;
		return get(st, en, l, mid, id << 1 | 0)
			+ get(st, en, mid, r, id << 1 | 1)
			+ 1LL * (min(en, r) - max(st, l)) * laz[id];
	}
} seg0, seg1;

void inc(int idx) {
	for (idx++; idx < maxn; idx += idx & -idx)
		fen[idx]++;
}

int get(int idx) {
	int ans = 0;
	for (; idx; idx -= idx & -idx)
		ans += fen[idx];
	return ans;
}

int get(int st, int en) {
	return get(en) - get(st);
}

int get_kth(int cnt) {
	int res = 0;
	for (int i = maxl - 1; i >= 0; i--)
		if (fen[res + (1 << i)] <= cnt) {
			res += 1 << i;
			cnt -= fen[res];
		}
	return res;
}

LL sum(LL cnt) {
	return cnt * (cnt + 1);
}

LL additional(LL cnt) {
	return sum(cnt / 2) + (cnt & 1LL ? cnt / 2 + 1 : 0LL);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		pos[a[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		self[i] = (i ? self[i - 1] : 0LL) + get(pos[i], n);
		inc(pos[i]);
//		cout << 4 << ' ' << self[i] << ' ' << seg0.get(0, 4) << ' ' << seg1.get(4, n) << ' ' << additional(i + 1) << endl;
		
		seg0.add(pos[i], n);
		seg1.add(0, pos[i] + 1);

		int mid = get_kth((i + 1) / 2);
		
		LL ans = self[i] + seg0.get(0, mid) + seg1.get(mid, n) - additional(i + 1);
//		cout << mid << ' ' << self[i] << ' ' << seg0.get(0, mid) << ' ' << seg1.get(mid, n) << ' ' << additional(i + 1) << endl;
		cout << ans << ' ';
	}
	cout << endl;
	return 0;
}