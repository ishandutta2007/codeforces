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
const int N = 1e5 + 7;
int n, m, a[N], las[N], lass[N], lasws[N], lasadd[N], ans[N];
int l[N], r[N];
vector<int> ve[N];
struct FenWT {
	int sz[N];
	void add(int x, int y) {
		if(x == 0) return;
		for(; x <= n; x += (x & -x)) sz[x] += y;
	}
	int qzh(int x) {
		int res = 0;
		for(; x; x -= (x & -x)) res += sz[x];
		return res;
	}
	int query(int l, int r) {
		return qzh(r) - qzh(l - 1);
	}
} sa, sb; 
int main() {
	// las :  i 
	// lass : 
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]);
	scanf("%d", &m);
	L(i, 1, m) scanf("%d%d", &l[i], &r[i]), ve[r[i]].push_back(i);
	L(i, 1, n) {
		sa.add(las[a[i]], -1);
		sa.add(i, 1);
		if(i - las[a[i]] != las[a[i]] - lass[a[i]]) {
			sb.add(lasadd[a[i]], -1);
			sb.add(lass[a[i]], 1);
			lasadd[a[i]] = lass[a[i]];
		}
		lass[a[i]] = las[a[i]];
		las[a[i]] = i;
		// ans =  - []
		for(int x : ve[i]) {
			int cnta = sa.query(l[x], i), cntb = sb.query(l[x], i);
			ans[x] = cnta + (cnta == cntb);
			// sb.query(l[x], i) :  ( \neq )
		}
	}
	L(i, 1, m) printf("%d\n", ans[i]);
	return 0;
}