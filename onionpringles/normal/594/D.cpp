#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int mod = 1000000007;
const int Big = 262144;
const int nump = 168;

int primes[nump] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };

inline void mul(int &a, int b) {
	a = (ll)a*b%mod;
}

int axpby(int a, int b) {
	//a,b must be less than 2^30
	int xx = 1; int yy = 0; int dd = a;
	int x = 0; int y = 1; int d = b;
	while (d) {
		int q = dd / d;

		int tmp = d;
		d = dd - d*q;
		dd = tmp;

		tmp = x;
		x = xx - x*q;
		xx = tmp;

		tmp = y;
		y = yy - y*q;
		yy = tmp;
	}
	if (xx < 0) xx += mod;
	return xx;
}

int inv[1000001];
vector<int> pr_ind[1000001];
int ind[1000001];
vector<int> pdivs[200000];
int tr[2 * Big];
int a[200000];
int ans[200000];
pair<pii, int> queries[200000];

void merge(int cur) {
	tr[cur] = tr[2 * cur];
	mul(tr[cur], tr[2 * cur + 1]);
}

void upd(int i, int val) {
	tr[Big + i] = val;
	int cur = (Big + i) / 2;
	while (cur > 0) {
		merge(cur);
		cur /= 2;
	}
}

void pfac(int j) {
	int tmp = a[j];
	for (int i = 0; i < nump; i++) {
		if (tmp % primes[i] == 0) {
			pdivs[j].push_back(primes[i]);
			pr_ind[primes[i]].push_back(j);
			while (tmp % primes[i] == 0) {
				tmp /= primes[i];
			}
		}
		if (tmp == 1) break;
	}
	if (tmp > 1) {
		pdivs[j].push_back(tmp);
		pr_ind[tmp].push_back(j);
	}
}

void move_prime(int p) {
	int &i = ind[p];
	int j = pr_ind[p][i];
	int tmp = tr[Big + j];
	mul(tmp, p);
	mul(tmp, inv[p - 1]);
	upd(j, tmp);
	i++;
	if (i == pr_ind[p].size()) return;
	j = pr_ind[p][i];
	tmp = tr[Big + j];
	mul(tmp, p-1);
	mul(tmp, inv[p]);
	upd(j, tmp);
}

void move_r(int l) {
	for (auto &p : pdivs[l]) {
		move_prime(p);
	}
}

int get(int nd, int ndl, int ndr, int l, int r) {
	if (ndr<l || ndl>r) return 1;
	else if (l <= ndl && ndr <= r) {
		return tr[nd];
	}
	else {
		int tmp = 1;
		int mid = (ndl + ndr) / 2;
		mul(tmp, get(2 * nd, ndl, mid, l, r));
		mul(tmp, get(2 * nd + 1, mid + 1, ndr, l, r));
		return tmp;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i <= 1000000; i++) inv[i] = axpby(i, mod);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		pfac(i);
		tr[Big + i] = a[i];
	}
	for (int i = n; i < Big; i++) tr[Big + i] = 1;
	for (int i = Big - 1; i > 0; i--) {
		merge(i);
	}
	memset(ind, 0, sizeof(ind));
	for (int i = 0; i < 1000001; i++) {
		if (!pr_ind[i].empty()) {
			int j = pr_ind[i][0];
			int tmp = tr[Big + j];
			mul(tmp, inv[i]);
			mul(tmp, i - 1);
			upd(j, tmp);
		}
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		queries[i] = mp(mp(l - 1, r - 1), i);
	}
	sort(queries, queries + q);
	int curl = 0;
	for (int i = 0; i < q; i++) {
		while (curl < queries[i].first.first) {
			move_r(curl);
			curl++;
		}
		int ret = get(1, 0, Big - 1, queries[i].first.first, queries[i].first.second);
		ans[queries[i].second] = ret;
	}
	for (int i = 0; i < q; i++) printf("%d\n", ans[i]);

}