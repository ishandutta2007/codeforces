#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = 1.2e6, xn = 5.1e6;
int n, q, b[N], xl[N], xr[N];

int p[xn + 7], tot;
int dit[xn + 7], lst[xn + 7], cnt[xn + 7], mn[xn + 7][9];
bool Prime[xn + 7];

int dc[N], ns[N];
void add(int x, int w) {
	for(; x; x -= x & -x) 
		dc[x] = min(dc[x], w);
}
int query(int x) {
	int ret = 1e9;
	for(; x <= n; x += x & -x) 
		ret = min(ret, dc[x]);
	return ret;
}
int arr[20], qwq[20], tp;
vi qry[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	L(i, 1, n) cin >> b[i];
	L(i, 2, xn) if(!Prime[i]) {
		p[++tot] = i;
		L(j, 2, xn / i) Prime[i * j] = 1;
		L(j, 1, xn / i) cnt[i * j] += 1, lst[i * j] = i;
	}
	L(i, 1, xn) dit[i] = i;
	L(i, 1, tot) {
		ll c = (ll) p[i] * p[i];
		for(ll o = c; o <= xn; o *= c) {
			L(t, 1, xn / o) 
				dit[t * o] /= c;
		}
	}
	L(i, 1, n) dc[i] = 1e9; 
	L(i, 1, q) cin >> xl[i] >> xr[i], qry[xr[i]].emplace_back(i);
	L(i, 1, n) {
		b[i] = dit[b[i]], tp = 0, me(qwq, 0);
		int rg = b[i];
		while(rg > 1) arr[++tp] = lst[rg], rg /= lst[rg];
		L(msk, 0, (1 << tp) - 1) {
			int o = 1;
			L(i, 1, tp) if(msk >> (i - 1) & 1) o *= arr[i];
			int z = cnt[b[i]] - cnt[o];
			L(v, 0, 8) if(mn[o][v]) qwq[z + v] = max(qwq[z + v], mn[o][v]);
			mn[o][z] = max(mn[o][z], i);
		}
		L(p, 0, 18) if(qwq[p]) add(qwq[p], p);
		for(const int &t : qry[i]) 
			ns[t] = query(xl[t]);
	}
	L(i, 1, q) 
		cout << ns[i] << '\n';
	return 0;
}