#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
typedef long long ll;
const int Big = 32768;

int ltime[15000];
int rtime[15000];
int query[30000];
int val[15000];
int mass[15000];

vector<int> tr[2 * 32768];
long long stk[20][1001];
long long cur[1001];
long long ans[30000][1001];
int sp = -1;
int k;
const int mod = 1000000007;
const int pp = 10000019;

void mul(int &a, int b) {
	a = (long long)a*b%mod;
}

void add(int &a, int b) {
	a = ((long long)a + b) % mod;
}

void insert(int nd, int ndl, int ndr, int l, int r, int val) {
	if (ndl > r || ndr < l) return;
	else if (l <= ndl && ndr <= r) {
		tr[nd].push_back(val);
	}
	else {
		int mid = (ndl + ndr) / 2;
		insert(2 * nd, ndl, mid, l, r, val);
		insert(2 * nd + 1, mid + 1, ndr, l, r, val);
	}
}

void savehist() {
	sp++;
	memcpy(stk[sp], cur, sizeof(cur));
}
void pophist() {
	memcpy(cur, stk[sp], sizeof(cur));
	sp--;
}

void dfs(int nd) {
	savehist();
	for (auto &x : tr[nd]) {
		for (int i = 1000; i >=0; i--) {
			if (mass[x] <= i) {
				cur[i] = max(cur[i], cur[i - mass[x]] + val[x]);
			}
		}
	}
	if (nd >= Big) {
		if(nd<Big+30000) memcpy(ans[nd - Big], cur, sizeof(cur));
	}
	else {
		dfs(2 * nd);
		dfs(2 * nd + 1);
	}
	pophist();
	return;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < 15000; i++) {
		ltime[i] = 0;
		rtime[i] = 29999;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d %d", val + i, mass + i);
	}
	int q;
	int timeq = 0; int avk = n;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int v, w;
			scanf("%d %d", val + avk, mass + avk);
			ltime[avk] = i;
			avk++;
		}
		else if (tp == 2) {
			int x;
			scanf("%d", &x);
			x--;
			rtime[x] = i;
		}
		else {
			query[timeq++] = i;
		}
	}
	for (int i = 0; i < avk; i++) {
		insert(1, 0, Big - 1, ltime[i], rtime[i], i);
	}
	memset(cur, 0, sizeof(cur));
	dfs(1);
	for (int i = 0; i < timeq; i++) {
		int t = query[i];
		int ppow = 1;
		int res = 0;
		for (int j = 1; j <= k; j++) {
			int tmp = ans[t][j]%mod;
			mul(tmp, ppow);
			add(res, tmp);
			mul(ppow, pp);
		}
		printf("%d\n", res);
		
	}
}