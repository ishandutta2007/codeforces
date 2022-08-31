#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 5e5 + 7, M = 1.5e7, mod = 998244353, mx = 1e9;
template<typename T> inline void cmax(T &x, T y) { if(x < y) x = y; }
template<typename T> inline void cmin(T &x, T y) { if(y < x) x = y; }
using namespace std;
int sum[M], tag1[M], tag2[M], ch[M][2], tot;
void ADD(int &id, int L, int R, int val1, int val2) { 
	if(!id) id = ++tot, tag1[id] = 1;
	tag1[id] = (ll) tag1[id] * val1 % mod;
	tag2[id] = ((ll) tag2[id] * val1 + val2) % mod;
	sum[id] = ((ll) sum[id] * val1 + (ll) val2 * (R - L + 1)) % mod; 
} 
void pushdown(int id, int L, int R) {
	int mid = (L + R) >> 1;
	ADD(ch[id][0], L, mid, tag1[id], tag2[id]);
	ADD(ch[id][1], mid + 1, R, tag1[id], tag2[id]);
	tag1[id] = 1, tag2[id] = 0;
}
void add(int &id, int L, int R, int l, int r, int val1, int val2) {
	if(!id) id = ++tot, tag1[id] = 1;
	if(l <= L && R <= r) return ADD(id, L, R, val1, val2), void();
	pushdown(id, L, R);
	int mid = (L + R) >> 1;
	if(l <= mid) add(ch[id][0], L, mid, l, r, val1, val2);
	if(r > mid) add(ch[id][1], mid + 1, R, l, r, val1, val2);
	sum[id] = (sum[ch[id][0]] + sum[ch[id][1]]) % mod;
}
int n, a[N], rt, ns = 1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		cin >> a[i];
		ADD(rt, 1, mx, mod - 1, ns);
		add(rt, 1, mx, a[i] + 1, mx, 0, 0);
		ns = sum[rt];
	}
	cout << ns << "\n";
	return 0;
}