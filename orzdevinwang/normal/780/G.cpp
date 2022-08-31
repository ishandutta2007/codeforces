#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 6e5 + 7;
const int mod = 1e9 + 7;
int h, w, n, tot, ans;
struct node {
	int s, l, r, h;
} f[N];
struct data {
	int cnt, high;
	data (int Cnt = 0, int High = 0) {
		cnt = Cnt, high = High;
	}
} ;
bool operator < (data aa, data bb) {
	return aa.high < bb.high;
}
multiset< data > S[N << 2];
int mn[N];
void upd(int id) {
	mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
}
int qry(int id, int L, int R, int l, int r, int qh) {
	if(mn[id] > qh) return 0;
	if(L == R) {
		int sum = 0;
		while(!S[id].empty() && (*S[id].begin()).high <= qh) (sum += (*S[id].begin()).cnt) %= mod, S[id].erase(S[id].begin());
		if(S[id].empty()) mn[id] = 2e9 + 7;
		else mn[id] = (*S[id].begin()).high;
		return sum;
	}
	int mid = (L + R) >> 1, res = 0;
	if(l <= mid) (res += qry(id << 1, L, mid, l, r, qh)) %= mod;
	if(r > mid) (res += qry(id << 1 | 1, mid + 1, R, l, r, qh)) %= mod;
	upd(id);
	return res;
}
void add(int id, int L, int R, int pos, data q) {
	if(L == R) return S[id].insert(q), mn[id] = min(mn[id], q.high), void();
	int mid = (L + R) >> 1;
	if(pos <= mid) add(id << 1, L, mid, pos, q);
	else add(id << 1 | 1, mid + 1, R, pos, q);
	upd(id);
}
int calc(int id, int L, int R) {
	if(L == R) {
		int res = 0;
		for(data s : S[id]) (res += s.cnt) %= mod;
		return res;
	} 
	int mid = (L + R) >> 1;
	return (calc(id << 1, L, mid) + calc(id << 1 | 1, mid + 1, R)) % mod;
}
void build(int id, int L, int R) {
	if(L == R) return mn[id] = h + 1, S[id].insert(data(1, h + 1)), void();
	int mid = (L + R) >> 1;
	build(id << 1, L, mid), build(id << 1 | 1, mid + 1, R), upd(id);
}
int dp[N];
int main() {
	memset(mn, 0x7f7f7f7f, sizeof(mn));
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> h >> w >> n;
	L(i, 1, n) cin >> f[i].h >> f[i].l >> f[i].r >> f[i].s;
	sort(f + 1, f + n + 1, [&](node aa, node bb) { return aa.h > bb.h; });
	build(1, 1, w);
	L(k, 1, n) {
		int all = qry(1, 1, w, f[k].l, f[k].r, f[k].h + f[k].s);
		// cout << all << "\n";
		if(f[k].l == 1) add(1, 1, w, f[k].r + 1, data (all * 2 % mod, f[k].h));
		else if(f[k].r == w) add(1, 1, w, f[k].l - 1, data (all * 2 % mod, f[k].h));
		else add(1, 1, w, f[k].l - 1, data (all, f[k].h)), add(1, 1, w, f[k].r + 1, data (all, f[k].h));
	}
	cout << calc(1, 1, w) << "\n";
	return 0;
}