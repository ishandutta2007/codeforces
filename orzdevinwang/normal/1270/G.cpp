#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, a[N], vis[N], id[N], f[N], tot;
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
void Main() {
	read(n);
	L(i, 1, n) read(a[i]), vis[i] = 0, a[i] = i - a[i];
	int now = 1;
	id[1] = f[tot = 1] = vis[1] = 1;
	while(!vis[a[now]]) now = f[++tot] = a[now], id[now] = tot, vis[now] = 1;
	print(tot - id[a[now]] + 1), puts("");
	L(i, id[a[now]], tot) print(f[i]), putchar(' ');
	puts("");
}
int main() {
	int T; read(T);
	while(T--) Main();
	return 0;
}