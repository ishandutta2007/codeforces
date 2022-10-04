#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <memory.h>
#include <algorithm>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;

pii xs[100000];
pii ys[100000];

int vis[100000];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		xs[i] = mp(x1 + x2, i);
		ys[i] = mp(y1 + y2, i);
	}
	sort(xs, xs + n);
	sort(ys, ys + n);
	memset(vis, 0, sizeof(vis));
	int mark = 0;
	long long _min = 5000000000000000000LL;
	for (int x = 0; x <= k; x++) {
		for (int y = 0; y <= k - x; y++) {
			for (int z = 0; z <= k - x - y; z++) {
				mark++;
				int w = k - x - y - z;
				int cnt = 0;
				int i = 0;
				while (1) {
					if (vis[xs[i].second] == mark) {
						i++;
						continue;
					}
					if (cnt == x) break;
					vis[xs[i].second] = mark;
					i++;
					cnt++;
				}
				int xmin = xs[i].first;

				cnt = 0;
				i = n - 1;
				while (1) {
					if (vis[xs[i].second] == mark) {
						i--;
						continue;
					}
					if (cnt == y) break;
					vis[xs[i].second] = mark;
					i--;
					cnt++;
				}
				int xmax = xs[i].first;

				cnt = 0; i = 0;
				while (1) {
					if (vis[ys[i].second] == mark) {
						i++;
						continue;
					}
					if (cnt == z) break;
					vis[ys[i].second] = mark;
					i++;
					cnt++;
				}
				int ymin = ys[i].first;

				cnt = 0; i = n - 1;
				while (1) {
					if (vis[ys[i].second] == mark) {
						i--;
						continue;
					}
					if (cnt == w) break;
					vis[ys[i].second] = mark;
					i--;
					cnt++;
				}
				int ymax = ys[i].first;

				long long dx = max(xmax - xmin, 2);
				if (dx % 2) dx++;
				long long dy = max(ymax - ymin, 2);
				if (dy % 2) dy++;
				_min = min(_min, dx*dy);
			}
		}
	}
	printf("%I64d", _min/4);

}


/*#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

const int BIG = 262144;
const int mod = 1000000007;
const int nump = 168;

int primes[nump] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };

set<int> pfac[2*BIG];
int euler[2 * BIG];

void ins(int i, int n) {
	set<int> tmp;
	int eu = 1;
	for (int j = 0; j < nump; j++) {
		if (primes[j] * primes[j]>n) break;
		int cnt = 0;
		while (n%primes[j] == 0) {
			n /= primes[j];
			cnt++;
		}
		if (cnt) {
			tmp.insert(primes[j]);
		}
	}
	if (n > 1) {
		tmp[n] = 1;
	}
	pfac[BIG + i] = tmp;
	return;
}
void upd() {
	for (int i = BIG - 1; i > 0; i--) {
		pfac[i] = pfac[2 * i];
		for (auto &x : pfac[2 * i + 1]) {
			auto it = pfac[i].find(x.first);
			if (it == pfac[i].end()) {
				pfac[i][x.first] = x.second;
			}
			else {
				pfac[i][x.first] += x.second;
			}
		}
	}
}

int pow(int n, int e) {
	if (e == 0) return 1;
	int tmp = pow(n, e / 2);
	tmp = (long long)tmp*tmp%mod;
	if (e % 2) {
		tmp = (long long)tmp*n%mod;
	}
	return tmp;
}

void mul(int &m, int n) {
	m = (long long)m*n%mod;
	return;
}

map<int, int> tmpm;

void query(int nd, int ql, int qr, int l, int r) {
	if (qr<l || ql>r) return;
	if (ql <= l && r <= qr) {
	//	printf("%d %d %d %d\n", ql, l, r, qr);
		for (auto &x : pfac[nd]) {
			auto it = tmpm.find(x.first);
			if (it == tmpm.end()) {
				tmpm[x.first] = x.second;
			}
			else {
				tmpm[x.first] += x.second;
			}
		}
	}
	else {
		query(2 * nd, ql, qr,l, (l+r)/2);
		query(2 * nd + 1, ql, qr, (l+r)/2+1, r);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int m;
		scanf("%d", &m);
		ins(i,m);
	}
	upd();
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--; r--;
		tmpm.clear();
		query(1, l, r, 0, BIG-1);
		int res = 1;
		for (auto &x : tmpm) {
			mul(res, pow(x.first, x.second - 1));
			mul(res, x.first - 1);
		}
		printf("%d\n", res);
	}
}*/