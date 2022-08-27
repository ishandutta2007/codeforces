#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch= getchar();
	return x * f;
}
const int N = 1e5 + 7;
const int B = 500;
int n, m, l = 1, r, Ans[N], a[N], cnt[N], ans;
struct asks {
	int id, l, r;
} ask[N];
int main() {
	n = read(), m = read();
	L(i, 1, n) a[i] = read(), (a[i] > n) && (a[i] = n + 1);
	L(i, 1, m) ask[i].l = read(), ask[i].r = read(), ask[i].id = i;
	sort(ask + 1, ask + m + 1, [&](asks aa, asks bb) { return aa.l / B == bb.l / B ? aa.r < bb.r : aa.l < bb.l; });
	L(i, 1, m) {
		while(l > ask[i].l) --l, ans -= (cnt[a[l]] == a[l]), ++ cnt[a[l]], ans += (cnt[a[l]] == a[l]);
		while(r < ask[i].r) ++r, ans -= (cnt[a[r]] == a[r]), ++ cnt[a[r]], ans += (cnt[a[r]] == a[r]);
		while(l < ask[i].l) ans -= (cnt[a[l]] == a[l]), -- cnt[a[l]], ans += (cnt[a[l]] == a[l]), ++l;
		while(r > ask[i].r) ans -= (cnt[a[r]] == a[r]), -- cnt[a[r]], ans += (cnt[a[r]] == a[r]), --r;
		Ans[ask[i].id] = ans;
	}
	L(i, 1, m) printf("%d\n", Ans[i]);
	return 0;
}