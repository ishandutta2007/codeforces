// You AK, wo bao ling. wo men de qian tu ... dou guang ming ! 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
int n, m, k;
int maxn[N << 3], flag[N << 3];
void AD(int x, int y) {
	flag[x] += y, maxn[x] += y;
}
void pushdown(int x) {
	if(flag[x]) AD(x << 1, flag[x]), AD(x << 1 | 1, flag[x]), flag[x] = 0;
}
void upd(int x) {
	maxn[x] = max(maxn[x << 1], maxn[x << 1 | 1]);
}
void add(int id, int L, int R, int l, int r, int val) {
	if(l <= L && R <= r) return AD(id, val), void();
	int mid = (L + R) / 2;
	pushdown(id);
	if(l <= mid) add(id << 1, L, mid, l, r, val);
	if(r > mid) add(id << 1 | 1, mid + 1, R, l, r, val);
	upd(id);
}
int query(int id, int L, int R, int l, int r) {
	if(l <= L && R <= r) return maxn[id];
	int mid = (L + R) / 2, res = -1e9;
	pushdown(id);
	if(l <= mid) res = max(res, query(id << 1, L, mid, l, r));
	if(r > mid) res = max(res, query(id << 1 | 1, mid + 1, R, l, r));
	return res;
} 
map<int, int> mp[N];
multiset<int> st;
int main() {
	scanf("%d%d%d", &n, &k, &m);
	L(i, 1, 2 * n) add(1, 1, n * 2, i, i, i);
	st.insert(n);
	while(m--) {
		int x, y, DY; scanf("%d%d", &x, &y);
		DY = y + abs(x - k);
		if(mp[x][y]) st.erase(st.lower_bound(DY)), add(1, 1, n * 2, 1, DY, -1), mp[x][y] = 0;
		else st.insert(DY), mp[x][y] = 1, add(1, 1, n * 2, 1, DY, 1), mp[x][y] = 1;
		int res = *st.rbegin();
		printf("%d\n", max(query(1, 1, n * 2, 1, res) - 1 - n, 0));
	}
	return 0;
}