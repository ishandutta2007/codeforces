#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int cur = 1, first[N];
struct Edge {
	int nxt , to;
	Edge(int nxt = 0 , int to = 0) : nxt(nxt) , to(to) {} 
}	e[N << 1];
int t1[N << 1], t2[N << 1], f[N << 1];
void con(int x, int y) {e[++cur] = Edge(first[x], y), first[x] = cur, t1[cur] = x, t2[cur] = y;}

int fib[36], siz[N];
int cut1, cut2, cut3;

void dfs(int x, int fa, int k) {
	siz[x] = 1;
	for (int i = first[x]; i; i = e[i].nxt) if(e[i].to != fa && !f[i]) {
		dfs(e[i].to, x, k), siz[x] += siz[e[i].to];
	}
	if(siz[x] == fib[k - 2] || siz[x] == fib[k - 1])
		cut1 = x, cut2 = fa;
}

int check(int x, int k) {
	if(k <= 1) return 1;
	cut1 = -1, cut2 = -1, cut3 = -1;
	dfs(x, 0, k);
	if(cut1 == -1) return 0;
	int wh = -1;
	for (int i = first[cut1]; i; i = e[i].nxt)
		if(e[i].to == cut2)
			wh = i;
	f[wh] = f[wh ^ 1] = 1;
	int tt1 = cut1, tt2 = cut2;
	if(siz[tt1] == fib[k - 2])
		return check(tt1, k - 2) & check(tt2, k - 1);
	else
		return check(tt1, k - 1) & check(tt2, k - 2);
}

int n;

int main() {
	fib[0] = fib[1] = 1;
	for (int i = 2; i <= 30; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		con(u, v), con(v, u);
	}
	int k = -1;
	for (int i = 1; i <= 30; i++)
		if(fib[i] == n) k = i;
	if(k == -1)
		return cout << "NO" << endl, 0;
	if(check(1, k)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}