#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f; 
}
int n, m, f[N], mn[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
void Main() {
	n = read(), m = read();
	L(i, 1, n) mn[i] = read(), f[i] = i;
	while(m --) {
		int x = read(), y = read();
		x = find(x), y = find(y);
		f[y] = x, mn[x] = min(mn[x], mn[y]);
	}
	ll ans = 0;
	L(i, 1, n) if(find(i) == i) ans += mn[i];
	printf("%lld\n", ans);
}
int main() {
	Main();
	return 0;
}