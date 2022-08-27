#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 4e5 + 7;
const int inf = 1e9 + 7;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar();
	return x * f;
}
int n, m, arr[N], tot, a[N], f[N], g[N], ans; // 
struct fenwick {
	int sz[N];
	void add(int x, int val) {
		for(; x <= tot; x += (x & -x)) sz[x] = max(sz[x], val);
	}
	int qry(int x) {
		int ans = 0;
		for(; x; x -= (x & -x)) ans = max(ans, sz[x]);
		return ans;
	}
} F, G;
int main() {
	n = read();
	L(i, 1, n) a[i] = read() - i, arr[++tot] = a[i], arr[++tot] = a[i] + 1;
	sort(arr + 1, arr + tot + 1);
	tot = unique(arr + 1, arr + tot + 1) - arr - 1;
	L(i, 1, n) a[i] = lower_bound(arr + 1, arr + tot + 1, a[i]) - arr;
	L(i, 1, n) {
		f[i + 1] = G.qry(a[i + 1] + 1), f[i] = max(F.qry(a[i]), f[i]) + 1, g[i] = G.qry(a[i]) + 1;
		ans = max(ans, f[i]);
		F.add(a[i], f[i]), G.add(a[i], g[i]);
	}
	printf("%d\n", max(0, n - ans - 1));
	return 0;
}