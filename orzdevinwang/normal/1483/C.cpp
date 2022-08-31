#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 5e5 + 7;
template<typename T> inline void cmax(T &x, T y) { if(x < y) x = y; }
template<typename T> inline void cmin(T &x, T y) { if(y < x) x = y; }
using namespace std;
int n, a[N], b[N], stk[N], top;
ll dp[N], mx[N << 2], lazy[N << 2];
void ADD(int id, ll val) { lazy[id] += val, mx[id] += val; } 
void pushdown(int id) {
	ADD(id << 1, lazy[id]), ADD(id << 1 | 1, lazy[id]), lazy[id] = 0;
}
void add(int id, int L, int R, int l, int r, ll val) {
	if(l <= L && R <= r) return ADD(id, val), void();
	pushdown(id);
	int mid = (L + R) >> 1;
	if(l <= mid) add(id << 1, L, mid, l, r, val);
	if(r > mid) add(id << 1 | 1, mid + 1, R, l, r, val);
	mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
}
ll query(int id, int L, int R, int l, int r) {
	if(l <= L && R <= r) return mx[id];
	pushdown(id);
	int mid = (L + R) >> 1; ll res = -1e17;
	if(l <= mid) res = max(res, query(id << 1, L, mid, l, r));
	if(r > mid) res = max(res, query(id << 1 | 1, mid + 1, R, l, r));
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		cin >> a[i];
	}
	L(i, 1, n) {
		cin >> b[i];
		while(top > 0 && a[i] < a[stk[top]]) 
			add(1, 1, n + 1, stk[top - 1] + 1, stk[top], - b[stk[top]]), --top;
		add(1, 1, n + 1, stk[top] + 1, i, b[i]);
		stk[++top] = i;
		dp[i] = query(1, 1, n + 1, 1, i);
		add(1, 1, n + 1, i + 1, i + 1, dp[i]);
	}
	cout << dp[n] << "\n";
	return 0;
}