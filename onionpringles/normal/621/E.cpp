#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#define mp make_pair
#define ni(n) scanf("%d", &(n))
#define mul(a,b) (ll)(a)*(b)%mod
#define add(a,b) ((ll)(a)+(b))%mod

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1000000007;
int x;

class poly {
public:
	int num[100];
	poly() {
		for (int i = 0; i < 100; i++) num[i] = 0;
	}
	poly(int *_num) {
		memcpy(num, _num, 100 * sizeof(int));
	}
	poly(int n) {
		num[0] = n;
		for (int i = 1; i < 100; i++) num[i] = 0;
	}
	poly operator*(const poly& other) const {
		int newnum[199];
		memset(newnum, 0, sizeof(newnum));
		for (int i = 0; i < 199; i++) {
			for (int j = 0; j <= i && j < 100; j++) {
				if (i - j >= 100) continue;
				newnum[i] = add(newnum[i], mul(num[j], other.num[i - j]));
			}
		}
		for (int i = 0; i < 199; i++) {
			if (i >= x) {
				int im = i%x;
				newnum[im] = add(newnum[im], newnum[i]);
				newnum[i] = 0;
			}
		}
		return poly(newnum);
	}
};

poly mypow(const poly& x, int e) {
	if (e == 0) return poly(1);
	poly tmp = mypow(x, e / 2);
	tmp = tmp*tmp;
	if (e % 2) tmp = x*tmp;
	return tmp;
}

bool isprime(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}

int phi(int n) {
	int m = n;
	for (int i = 2; i <= n; i++) {
		if (n%i == 0 && isprime(i)) {
			m = m*(i - 1) / i;
		}
	}
	return m;
}


void upd(poly& p) {
	int newblk[100];
	memset(newblk, 0, sizeof(newblk));
	for (int i = 0; i < x; i++) {
		int nn = i * 10 % x;
		newblk[nn] += p.num[i];
	}
	memcpy(p.num, newblk, sizeof(p.num));
	return;
}

int pow3(int n, int e) {
	if (e == 0) return 1;
	int tmp = pow3(n, e / 2);
	tmp = mul(tmp, tmp);
	if (e % 2) tmp = mul(tmp, n);
	return tmp;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, b, k;
	scanf("%d %d %d %d", &n, &b, &k, &x);
	poly p;
	for (int i = 0; i < n; i++) {
		int bb;
		ni(bb);
		p.num[bb%x]++;
	}
	int px = phi(x);
	poly ans = poly(1);
	for (int i = 0; i < 6 && i<b; i++) {
		ans = ans*p;
		upd(p);
	}
	for (int i = 0; i < px && 7+i<=b; i++) {
		int E = 1 + (b - 7 - i) / px;
		if (E < 0) break;
		ans = ans*mypow(p, E);
		upd(p);
	}
	
	printf("%d\n", ans.num[k]);
	return 0;
}