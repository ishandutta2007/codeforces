#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;

const int N = 2e5 + 7;

int B, Bs; 

ll sum[N], val[N]; 
inline void add(int x, ll y) {
	val[x] += y;
	sum[(x + B - 1) / B] += y; 
}
inline ll pre (int x) {
	ll ret = 0;
	int sy = x / B;
	L(i, 1, sy) ret += sum[i];
	L(i, sy * B + 1, x) ret += val[i];
	return ret;
}

int n, m, G, Gs;
int ta[N], tb[N], tc[N];
int a[N], b[N], c[N];

int qop[N], qk[N], qx[N];
int cnt[N];

ll ns[N];

int arr[N], atot;
int *qwq[N];

ll dp[N][4][4], ib[N][4];
bool vis[N];

vi st[N];

ll h[3];

bool chk(int x, int w) {
	return (a[x] == w) || (b[x] == w) || (c[x] == w);
}

bool co[N];
ll f[N];
inline void Del(int w) {
	if(!co[w]) return ;
	for(const int &u : st[w]) 
		if(c[u] == w && f[u]) add(u, -f[u]), f[u] = 0;
}

inline void Ins (int w) {
	if(!co[w]) return ;
	h[0] = 1, h[1] = 0, h[2] = 0; 
	for(const int &u : st[w]) {
		if(c[u] == w && h[2]) f[u] = h[2], add(u, f[u]);
		if(a[u] == w) h[2] += h[1];
		if(b[u] == w) h[1] += h[0];
	}
} 

inline void init (int x, int w) {
	int mc = (x - 1) * G + 1;
	me(dp[mc], 0);
	L(o, 0, 3) dp[mc][o][o] = 1;
	if(b[arr[mc]] == w) dp[mc][0][1] += 1;
	if(a[arr[mc]] == w) dp[mc][1][2] += 1;
	if(c[arr[mc]] == w) dp[mc][2][3] += 1;
	L(i, (x - 1) * G + 2, min(x * G, atot)) {
		L(o, 0, 3) L(u, o, 3) dp[i][o][u] = dp[i - 1][o][u];
		if(b[arr[i]] == w) L(o, 0, 0) dp[i][o][1] += dp[i - 1][o][0];
		if(a[arr[i]] == w) L(o, 0, 1) dp[i][o][2] += dp[i - 1][o][1];
		if(c[arr[i]] == w) L(o, 0, 2) dp[i][o][3] += dp[i - 1][o][2];
	}
}

inline void pit(int x) {
	L(i, x, Gs) {
		me(ib[i], 0);
		L(a, 0, 3) 
			L(b, a, 3)
				ib[i][b] += ib[i - 1][a] * dp[min(i * G, atot)][a][b];
	}
}

int main() {
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> n >> m ;
	
	B = sqrt(n), B = min(B, n);
	Bs = (n + B - 1) / B;
	
	L(i, 1, n) cin >> a[i], ta[i] = a[i];
	L(i, 1, n) cin >> tb[i];
	L(i, 1, n) cin >> tc[i];
	L(i, 1, n) b[i] = tb[a[i]], c[i] = tc[a[i]];
	
	L(i, 1, n) cnt[a[i]] += 1, cnt[b[i]] += 1, cnt[c[i]] += 1;
	
	L(i, 1, m) {
		cin >> qop[i] >> qk[i];
		if(qop[i] == 1) 
			cin >> qx[i], cnt[qx[i]] += 1, cnt[tb[qx[i]]] += 1, cnt[tc[qx[i]]] += 1;
	} 
	
	L(i, 1, n) 
		qwq[i] = new int [cnt[i]];
	
	me(cnt, 0);
	L(i, 1, n) 
		qwq[a[i]][cnt[a[i]] ++] = i, 
		qwq[b[i]][cnt[b[i]] ++] = i, 
		qwq[c[i]][cnt[c[i]] ++] = i;
	
	L(i, 1, m) 
		if(qop[i] == 1) 
			qwq[qx[i]][cnt[qx[i]] ++] = qk[i], 
			qwq[tb[qx[i]]][cnt[tb[qx[i]]] ++] = qk[i], 
			qwq[tc[qx[i]]][cnt[tc[qx[i]]] ++] = qk[i]; 
	
	
	ib[0][0] = 1;
	L(w, 1, n) if(cnt[w] > B * 2.3) {
		sort(qwq[w], qwq[w] + cnt[w]);
		cnt[w] = unique(qwq[w], qwq[w] + cnt[w]) - qwq[w];
		
		atot = cnt[w];
		L(i, 0, cnt[w] - 1) arr[i + 1] = qwq[w][i]; 
		L(i, 1, atot) vis[arr[i]] = true; 
		
		G = sqrt(atot);
		Gs = (atot + G - 1) / G;
		
		L(i, 1, Gs) init(i, w); 
		pit(1);
		
		L(i, 1, m) {
			if(qop[i] == 1) {
				if(vis[qk[i]]) {
					a[qk[i]] = qx[i], b[qk[i]] = tb[qx[i]], c[qk[i]] = tc[qx[i]]; 
					int lb = lower_bound(arr + 1, arr + atot + 1, qk[i]) - arr;
					init((lb + G - 1) / G, w), pit((lb + G - 1) / G); 
				} 
			} else {
				int x = upper_bound(arr + 1, arr + atot + 1, qk[i]) - arr - 1, 
					p = (x - 1) / G;
				if(x > 0)
					L(j, 0, 3) ns[i] += ib[p][j] * dp[x][j][3];
			}
		}
		
		L(i, 1, atot) {
			vis[arr[i]] = false;
			a[arr[i]] = ta[arr[i]];
			b[arr[i]] = tb[a[arr[i]]];
			c[arr[i]] = tc[a[arr[i]]];	
		}
	} else co[w] = true;
	
	L(i, 1, n) {
		if(co[a[i]]) st[a[i]].emplace_back(i);
		if(co[b[i]]) st[b[i]].emplace_back(i);
		if(co[c[i]]) st[c[i]].emplace_back(i);
	}
	L(i, 1, n) if(sz(st[i])) 
		sort(st[i].begin(), st[i].end()), 
		st[i].erase(unique(st[i].begin(), st[i].end()), st[i].end()), Ins(i);
	
	L(i, 1, m) {
		if(qop[i] == 1) {
			if(a[qk[i]] != qx[i]) {
				int wa = a[qk[i]], wb = b[qk[i]], wc = c[qk[i]];
				int ra = qx[i], rb = tb[qx[i]], rc = tc[qx[i]];
				
				if(!co[wa]) wa = -1;
				if(!co[wb] || wb == wa) wb = -1;
				if(!co[wc] || wc == wb || wc == wa) wc = -1;
				
				if(!co[ra]) ra = -1;
				if(!co[rb] || rb == ra) rb = -1;
				if(!co[rc] || rc == rb || rc == ra) rc = -1;
				
				if(ra > 0) Del(ra);
				if(rb > 0) Del(rb);
				if(rc > 0) Del(rc);
				if(wa > 0 && wa != ra && wa != rb && wa != rc) Del(wa);
				if(wb > 0 && wb != ra && wb != rb && wb != rc) Del(wb);
				if(wc > 0 && wc != ra && wc != rb && wc != rc) Del(wc);
				
				if(wa > 0 && wa != ra && wa != rb && wa != rc) 
					st[wa].erase(lower_bound(st[wa].begin(), st[wa].end(), qk[i]));
				if(wb > 0 && wb != ra && wb != rb && wb != rc) 
					st[wb].erase(lower_bound(st[wb].begin(), st[wb].end(), qk[i]));
				if(wc > 0 && wc != ra && wc != rb && wc != rc) 
					st[wc].erase(lower_bound(st[wc].begin(), st[wc].end(), qk[i]));
				
				if(ra > 0 && ra != wa && ra != wb && ra != wc) 
					st[ra].insert(lower_bound(st[ra].begin(), st[ra].end(), qk[i]), qk[i]);
				if(rb > 0 && rb != wa && rb != wb && rb != wc) 
					st[rb].insert(lower_bound(st[rb].begin(), st[rb].end(), qk[i]), qk[i]);
				if(rc > 0 && rc != wa && rc != wb && rc != wc) 
					st[rc].insert(lower_bound(st[rc].begin(), st[rc].end(), qk[i]), qk[i]);
				
				a[qk[i]] = qx[i];
				b[qk[i]] = tb[qx[i]];
				c[qk[i]] = tc[qx[i]];
					
				if(ra > 0) Ins(ra);
				if(rb > 0) Ins(rb);
				if(rc > 0) Ins(rc);
				if(wa > 0 && wa != ra && wa != rb && wa != rc) Ins(wa);
				if(wb > 0 && wb != ra && wb != rb && wb != rc) Ins(wb);
				if(wc > 0 && wc != ra && wc != rb && wc != rc) Ins(wc);
			}
		} else cout << ns[i] + pre(qk[i]) << '\n';
	}
	return 0;
}