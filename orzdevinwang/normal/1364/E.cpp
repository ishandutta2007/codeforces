#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
#define putsl puts("")
using namespace std;
mt19937 orz(233);
const int N = 3e3 + 6;
int n, m, k, stk[N], tot, zero, ans[N];
int vis[N][N];
int cnt = 0;
int ask(int x, int y) {
	if(vis[x][y]) return vis[x][y];
	printf("? %d %d\n", x, y);
	// cout << "? " << x << " " << y << endl;
	fflush(stdout);
	int tmp; scanf("%d", &tmp); return vis[x][y] = vis[y][x] = tmp;
}
int radp(int x, int y) {
	int ch = orz() % n + 1;
	while(ch == x || ch == y) ch = orz() % n + 1;
	return ch;
}
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0), cout.tie(0);

	// cin >> n;
	scanf("%d", &n);
	L(i, 1, n) stk[++tot] = i;
	while(tot > 2) {
		int A = stk[tot], B = stk[tot - 1], C = stk[tot - 2], f1 = ask(A, B), f2 = ask(A, C);
		if(f1 == f2) --tot; // del : A
		else if(f1 < f2) stk[tot - 2] = stk[tot - 1], stk[tot - 1] = stk[tot], --tot; // del : C
		else stk[tot - 1] = stk[tot], --tot; // del : B
	}
	int C = radp(stk[1], stk[2]), f1 = ask(C, stk[1]), f2 = ask(C, stk[2]);
	while(f1 == f2) C = radp(stk[1], stk[2]), f1 = ask(C, stk[1]), f2 = ask(C, stk[2]);
	if(f1 < f2) zero = stk[1];
	else zero = stk[2];
	L(i, 1, n) if(i != zero) ans[i] = ask(zero, i);
	printf("! ");
	L(i, 1, n) printf("%d ", ans[i]);
	fflush(stdout);
	return 0;
}