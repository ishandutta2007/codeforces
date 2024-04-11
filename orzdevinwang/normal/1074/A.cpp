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
const int mod = 998244353;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x * f; 
}
int n, m, x[N], len[N], tot, ans = 1e9;
int main() {
	n = read(), m = read();
	L(i, 1, n) x[i] = read();
	L(i, 1, m) {
		int l, r, y; 
		l = read(), r = read(), y = read();
		if(l ^ 1) continue;
		len[++tot] = r;
	}
	sort(len + 1, len + tot + 1);
	sort(x + 1, x + n + 1);
	int now = 1;
	x[n + 1] = 1e9;
	L(i, 0, n) {
		while(len[now] < x[i + 1] && now <= tot) ++now; 
		ans = min(ans, i + tot - now + 1);
	}
	printf("%d\n", ans);
	return 0;
}