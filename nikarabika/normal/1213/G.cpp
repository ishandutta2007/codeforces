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

const int maxn = 2e5 + 10;
int frm[maxn],
	too[maxn],
	wei[maxn],
	ord[maxn],
	par[maxn],
	n, q;
LL ans[maxn],
   curans;
pii quer[maxn];

bool cmp(int i, int j) {
	return wei[i] < wei[j];
}

int root(int u) {
	return par[u] < 0 ? u : par[u] = root(par[u]);
}

void merge(int u, int v) {
	if ((u = root(u)) == (v = root(v)))
		return;
	if (par[u] > par[v])
		swap(u, v);
	curans += 1LL * par[u] * par[v];
	par[u] += par[v];
	par[v] = u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> q;
	int m = n - 1;
	for (int i = 0; i < m; i++) {
		ord[i] = i;
		cin >> frm[i] >> too[i] >> wei[i];
		frm[i]--, too[i]--;
	}
	sort(ord, ord + m, cmp);
	for (int i = 0; i < q; i++) {
		cin >> quer[i].L;
		quer[i].R = i;
	}
	sort(quer, quer + q);
	int ptr = 0;
	for (int i = 0; i < q; i++) {
		while (ptr < m and wei[ord[ptr]] <= quer[i].L)
			merge(frm[ord[ptr]], too[ord[ptr]]), ptr++;
		ans[quer[i].R] = curans;
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}