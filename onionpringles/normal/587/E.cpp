#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>

using namespace std;
const int Big = 262144;

vector<int> LI(vector<int> nums2) {
	int isleading[64];
	for (int i = 0; i < 64; i++) isleading[i] = 0;
	vector<int> nums = nums2;
	int sz = nums.size();
	for (int i = 0; i < sz; i++) {
		if (nums[i] == 0)continue;
		int lbit = nums[i] & (-nums[i]);
		isleading[i] = 1;
		for (int j = i + 1; j < sz; j++) {
			if (nums[j] & lbit) nums[j] ^= nums[i];
		}
	}
	vector<int> res;
	for (int i = 0; i < sz; i++) {
		if (isleading[i]) res.push_back(nums2[i]);
	}
	return res;
}

int mod_tr[2 * Big];
vector<int> tr[2 * Big];
int a[200000];

void mod_tr_q(int nd, int ndl, int ndr, int l, int r, int k) {
	if (ndr < l || r < ndl) return;
	else if (l <= ndl && ndr <= r) {
		mod_tr[nd] ^= k;
		return;
	}
	else {
		int mid = (ndl + ndr) / 2;
		mod_tr_q(2 * nd, ndl, mid, l, r, k);
		mod_tr_q(2 * nd + 1, mid + 1, ndr, l, r, k);
	}
}

void push(int nd) {
	if (nd >= Big) return;
	if (mod_tr[nd] == 0) return;
	mod_tr[2 * nd] ^= mod_tr[nd];
	mod_tr[2 * nd + 1] ^= mod_tr[nd];
	mod_tr[nd] = 0;
}

void upd(int nd) {
	if (nd > 1) upd(nd / 2);
	push(nd);
}

int mod_tr_get(int i) {
	upd(Big+i);
	return mod_tr[Big + i];
}


void merge(int nd) {
	tr[nd] = tr[2 * nd];
	for (auto &x : tr[2 * nd + 1]) tr[nd].push_back(x);
	tr[nd] = LI(tr[nd]);
}

void tr_set(int i, int val) {
	tr[Big + i][0] ^= val;
	int cur = (Big + i) / 2;
	while (cur > 0) {
		merge(cur);
		cur /= 2;
	}
}

vector<int> get_basis(int nd, int ndl, int ndr, int l, int r) {
	vector<int> res;
	if (ndr < l || r < ndl || l>r) return res;
	else if (l <= ndl && ndr <= r) {
		return LI(tr[nd]);
	}
	else {
		int mid = (ndl + ndr) / 2;
		res = get_basis(2 * nd, ndl, mid, l, r);
		vector<int> tmp;
		tmp = get_basis(2 * nd + 1, mid + 1, ndr, l, r);
		for (auto &x : tmp) res.push_back(x);
		res = LI(res);
		return res;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n - 1; i++) {
		int hh = a[i] ^ a[i + 1];
		tr[Big + i].push_back(hh);
	}
	for (int i = Big - 1; i > 0; i--) {
		merge(i);
	}
	for (int i = 0; i < q; i++) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int l, r, k;
			scanf("%d %d %d", &l, &r, &k);
			l--; r--;
			mod_tr_q(1, 0, Big - 1, l, r, k);
			if (l >= 1) {
				tr_set(l - 1, k);
			}
			if (r < n - 1) {
				tr_set(r, k);
			}
		}
		else {
			int l, r;
			scanf("%d %d", &l, &r); l--; r--;
			vector<int> ret = get_basis(1, 0, Big - 1, l, r-1);
			ret.push_back(a[l] ^ mod_tr_get(l));
			ret = LI(ret);
			int sz = ret.size();
			printf("%lu\n", (unsigned int)(1 << sz));
		}
	}
	return 0;
}