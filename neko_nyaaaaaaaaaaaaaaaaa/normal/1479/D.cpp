#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 300000;
const int BLOCK_SIZE = 550;
int a[MAXN];

struct sqrt_block{
	int cnt[MAXN], cntb[BLOCK_SIZE];

	void tog(int x) {
		//cout << "New update: " << x << '\n';
		int block_id = x/BLOCK_SIZE;

		if (cnt[x] % 2) {
			cntb[block_id]--; 
		} else {
			cntb[block_id]++;
		}
		cnt[x] ^= 1;
	}

	int calc(int l, int r) {
		//cout << "New query: " << l << ' ' << r << '\n';
		int lblock = l/BLOCK_SIZE;
		int lblock_id = l % BLOCK_SIZE;
	
		int rblock = r/BLOCK_SIZE;
		int rblock_id = r % BLOCK_SIZE;

		if (lblock == rblock) {
			for (int i = lblock_id, j = l; i <= rblock_id; i++, j++) {
				//cout << j << ' ' << cnt[j] << '\n';
				if (cnt[j] % 2) return j+1;
			}
		} else {
			for (int i = lblock_id, j = l; i < BLOCK_SIZE; i++, j++) {
				//cout << j << ' ' << cnt[j] << '\n';
				if (cnt[j] % 2) return j+1;
			}
			for (int i = 0, j = rblock*BLOCK_SIZE; i <= rblock_id; i++, j++) {
				//cout << j << ' ' << cnt[j] << '\n';
				if (cnt[j] % 2) return j+1;
			}
		}

		for (int ii = lblock + 1; ii < rblock; ii++) {
			if (cntb[ii] > 0) {
				for (int i = 0, j = ii*BLOCK_SIZE; i < BLOCK_SIZE; i++, j++) {
					//cout << j << ' ' << cnt[j] << '\n';
					if (cnt[j] % 2) return j+1;
				}
			}
		}

		return -1;
	}
} sq;

void add(int ind, int end) { sq.tog(a[ind]); } // add a[ind] (end = 0 or 1)
void del(int ind, int end) { sq.tog(a[ind]); } // remove a[ind]
int calc(int l, int r) { return sq.calc(l, r); } // compute current answer

vi moTree(vector<array<int, 4>> Q, vector<vi>& ed, int root=0){
	int N = sz(ed), pos[2] = {}, blk = 550; // ~N/sqrt(Q)
	vi s(sz(Q)), res = s, I(N), L(N), R(N), in(N), par(N);
	add(0, 0), in[0] = 1;
	auto dfs = [&](int x, int p, int dep, auto& f) -> void {
		par[x] = p;
		L[x] = N;
		if (dep) I[x] = N++;
		for (int y : ed[x]) if (y != p) f(y, x, !dep, f);
		if (!dep) I[x] = N++;
		R[x] = N;
	};
	dfs(root, -1, 0, dfs);
#define K(x) pii(I[x[0]] / blk, I[x[1]] ^ -(I[x[0]] / blk & 1))
	iota(all(s), 0);
	sort(all(s), [&](int s, int t){ return K(Q[s]) < K(Q[t]); });
	for (int qi : s) rep(end,0,2) {
		int &a = pos[end], b = Q[qi][end], i = 0;
#define step(c) { if (in[c]) { del(a, end); in[a] = 0; } \
                  else { add(c, end); in[c] = 1; } a = c; }
		while (!(L[b] <= L[a] && R[a] <= R[b]))
			I[i++] = b, b = par[b];
		while (a != b) step(par[a]);
		while (i--) step(I[i]);
		if (end) res[qi] = calc(Q[qi][2], Q[qi][3]);
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i]--;
	}
	vector<vi> ed(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v; u--, v--;
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	vector<array<int, 4>> Q(q);
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> Q[i][j]; Q[i][j]--;
		}
	}
	vi ans = moTree(Q, ed);
	for (int i: ans) cout << i << '\n';
	
	return 0;
}