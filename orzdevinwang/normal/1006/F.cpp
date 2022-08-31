#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 22;
const int M = 1e6 + 7;
int n, m, B;
ll k, now, a[N][N], ans;
map<ll, int> mp[N];
void dfsa(int x, int y, int len) {
	if(x > n || y > m) return;
	if(len == B) return mp[x][now] ++, void(); 
	now ^= a[x][y], dfsa(x + 1, y, len + 1), dfsa(x, y + 1, len + 1), now ^= a[x][y];
}
void dfsb(int x, int y, int len) {
	if(x <= 0 || y <= 0) return;
	if(len == n + m - 2 - B) return ans += mp[x][now ^ a[x][y] ^ k], void(); 
	now ^= a[x][y], dfsb(x - 1, y, len + 1), dfsb(x, y - 1, len + 1), now ^= a[x][y];
}
int main() {
	scanf("%d%d%lld", &n, &m, &k), B = (n + m - 2) / 2;
	L(i, 1, n) L(j, 1, m) scanf("%lld", &a[i][j]);
	dfsa(1, 1, 0), dfsb(n, m, 0); 
	printf("%lld\n", ans);
	return 0;
}