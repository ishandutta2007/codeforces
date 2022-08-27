#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int inf = 1e9 + 7;
const int N = 2e5 + 7;
ll ans = 0;
int n, m, head[26], nxt[N], now;
char s[N];
int sz[N];
void add(int x, int y) { for(int i = x; i <= n; i += (i & -i)) sz[i] += y; }
int query(int x) { int res = 0; for(int i = x; i; i -= (i & -i)) res += sz[i]; return res; }
int main() {
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; i++) 
		nxt[i] = head[s[i] - 'a'], head[s[i] - 'a'] = i, add(i, 1);
	for(int i = 1; i <= n; i++) {
		ans += n - i + 1 - query(head[s[i] - 'a']);
		add(head[s[i] - 'a'], -1);
		head[s[i] - 'a'] = nxt[head[s[i] - 'a']];
	}
	printf("%lld\n", ans);
    return 0;
}