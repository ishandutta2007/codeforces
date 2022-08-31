#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define putsl puts("")
using namespace std;
const int N = 1e5 + 7;
const int B = 320;
const int S = B + 5;
const int iS = N / B + 5;
const int M = 20;
template<typename T> inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch - '0');
	x *= f;
}
template<typename T> inline void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) print(x / 10);
	putchar(x % 10 + '0');
}
int n, m, q, bcnt, l[iS], r[iS];
char s[N][M], opt[5];
struct node {
	int line[M], to[M];
} f[N];
node operator + (node aa, node bb) {
	node res;
	L(i, 1, m) {
		if(aa.to[i] > 0) res.to[i] = bb.to[aa.to[i]], res.line[i] = bb.line[aa.to[i]];
		else res.to[i] = aa.to[i], res.line[i] = aa.line[i];
	}
	return res;
}
int getid(int x) {
	return (x - 1) / B + 1;
}
int find(int now, int x) {
	if(f[now].to[x]) return f[now].to[x];
	if(s[now][x] == '^') return f[now].to[x] = x;
	if(s[now][x] == '>') {
		if(x == m) return f[now].to[x] = -1;
		if(s[now][x + 1] == '<') return f[now].to[x] = -3;
		return f[now].to[x] = find(now, x + 1);
	}
	if(s[now][x] == '<') {
		if(x == 1) return f[now].to[x] = -2;
		if(s[now][x - 1] == '>') return f[now].to[x] = -3;
		return f[now].to[x] = find(now, x - 1);
	}
	assert(0);
}
void rebuild(int x) {
	L(i, l[x], r[x]) {
		L(j, 1, m) f[i].to[j] = 0, f[i].line[j] = i;
		L(j, 1, m) find(i, j);
		if(i != l[x]) f[i] = f[i] + f[i - 1];
	}
}
node getline(int x) {
	node res = f[x];
	R(i, getid(x) - 1, 1) res = res + f[r[i]];
	return res;
}
int main() {
	read(n), read(m), read(q), bcnt = getid(n);
	L(i, 1, n) scanf("%s", s[i] + 1);
	L(i, 1, bcnt) l[i] = (i - 1) * B + 1, r[i] = min(i * B, n);
	L(i, 1, bcnt) rebuild(i);
	int tmp = 0;
	while(q--) {
		++tmp;
		int x, y;
		scanf("%s", opt), read(x), read(y);
		if(opt[0] == 'A') {
			node res = getline(x);
			if(res.to[y] == -3) printf("-1 -1\n");
			if(res.to[y] == -2) printf("%d 0\n", res.line[y]);
			if(res.to[y] == -1) printf("%d %d\n", res.line[y], m + 1);
			if(res.to[y] > 0) printf("0 %d\n", res.to[y]);
		}
		else {
			scanf("%s", opt), s[x][y] = opt[0];
			rebuild(getid(x));
		}
	}
	return 0;
}