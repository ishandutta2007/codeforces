#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = (1 << 21);
int n, m, k, a[N];
struct ST { // Get min
	int n, st[20][N], a[N], lg[N];
	void init() {
		L(i, 2, n) lg[i] = lg[i >> 1] + 1;
		L(i, 1, n) st[0][i] = i;
		L(i, 1, 19) L(j, 1, n - (1 << i) + 1) 
			st[i][j] = a[st[i - 1][j]] < a[st[i - 1][j + (1 << (i - 1))]] ? st[i - 1][j] : st[i - 1][j + (1 << (i - 1))];
	}
	inline int qrypos(int l, int r) { 
		if(l > r) assert (0);
		int p = lg[r - l + 1]; 
		return a[st[p][l]] < a[st[p][r - (1 << p) + 1]] ? st[p][l] : st[p][r - (1 << p) + 1]; 
	}
	inline int qry (int l, int r) {
		return a[qrypos (l, r)];
	}
} s;
int ql[N], qr[N], f[N];
int stk[N], tp;
ll ns[N];
vi S[N];

int tag[N << 2]; 
ll sum[N << 2];
void AD (int id, int L, int R, int val) {
	tag[id] += val, sum[id] += (ll) (R - L + 1) * val;
}
void push (int id, int L, int R) {
	if(!tag[id]) return;
	int mid = (L + R) >> 1; 
	AD(id << 1, L, mid, tag[id]), AD(id << 1 | 1, mid + 1, R, tag[id]), tag[id] = 0;
}
void upd (int id) {
	sum[id] = sum[id << 1] + sum[id << 1 | 1];
}
int tw[N];
void add(int x, int L, int R, int l, int r, int val) {
//	L(i, l, r) 
//		tw[i] += val;
	if(l <= L && R <= r) return AD (x, L, R, val);
	int mid = (L + R) >> 1;
	push(x, L, R);
	if(l <= mid) add (x << 1, L, mid, l, r, val);
	if(r > mid) add (x << 1 | 1, mid + 1, R, l, r, val);
	upd (x);
}
ll query (int x, int L, int R, int l, int r) {
//	ll ret = 0;
//	L(i, l, r) ret += tw[i];
//	return ret;
	if(l <= L && R <= r) return sum[x];
	int mid = (L + R) >> 1;
	ll res = 0;
	push (x, L, R);
	if(l <= mid) res += query(x << 1, L, mid, l, r);
	if(r > mid) res += query(x << 1 | 1, mid + 1, R, l, r);
	return res;
}
void clear (int x, int L, int R) {
//	memset(tw, 0, sizeof(tw));
	sum[x] = tag[x] = 0;
	if(L == R) return ;
	int mid = (L + R) >> 1;
	clear (x << 1, L, mid), clear (x << 1 | 1, mid + 1, R);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	L(i, 1, n) cin >> a[i], s.a[i] = a[i];
	s.n = n, s.init();
	L(i, 1, m) {
		cin >> ql[i] >> qr[i];
		if(ql[i] == qr[i]) ns[i] = a[ql[i]];
		else S[ql[i] + 1].push_back(i);	
	}
	L(ls, 1, k) {
		int Len = (n - ls) / k + 1;
		tp = 0, stk[0] = Len + 1;
		R(i, Len, 1) {
			int z = (i - 1) * k + ls, F = s.qry (z, min (z + k - 1, n));
			
			while (tp > 0 && F <= f[stk[tp]]) {
				if(stk[tp - 1] > stk[tp]) add (1, 0, Len, stk[tp], stk[tp - 1] - 1, -f[stk[tp]]);
				--tp;
			} 
			f[i] = F;
			stk[++tp] = i;
			add (1, 0, Len, stk[tp], stk[tp - 1] - 1, f[i]);
			
			f[i - 1] = a[z - 1];
			while (tp > 0 && f[i - 1] <= f[stk[tp]]) {
				if(stk[tp - 1] > stk[tp]) add (1, 0, Len, stk[tp], stk[tp - 1] - 1, -f[stk[tp]]);
				--tp;
			} 
			stk[++tp] = i - 1;
			add (1, 0, Len, stk[tp], stk[tp - 1] - 1, f[i - 1]);
			for (const int &t : S[z]) {
				int r = (qr[t] - ls + 1) / k; 
				ns[t] = query (1, 0, Len, i - 1, r);
			}
		}
		clear (1, 0, Len);
	}
	L(i, 1, m) cout << ns[i] << '\n';
	return 0;
}