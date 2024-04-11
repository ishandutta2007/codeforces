// You AK, wo bao ling. wo men de qian tu ... dou guang ming ! 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define uint unsigned int
using namespace std;
const int N = 1e5 + 7;
int n, m, mod, siz[N], f[N], cnt, sum = 1;
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
	scanf("%d%d%d", &n, &m, &mod);
	cnt = n;
	L(i, 1, n) f[i] = i, siz[i] = 1;
	L(i, 1, m) {
		int u, v; scanf("%d%d", &u, &v);
		if(find(u) != find(v)) --cnt, siz[find(v)] += siz[find(u)], f[find(u)] = find(v); 
	}
	if(cnt == 1) return printf("%d\n", 1 % mod), 0;
	L(i, 1, cnt - 2) sum = 1ll * sum * n % mod;
	L(i, 1, n) if(find(i) == i) sum = 1ll * sum * siz[i] % mod;
	printf("%d\n", sum);
	return 0;
}