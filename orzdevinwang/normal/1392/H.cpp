#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e6 + 7;
const int mod = 998244353;
int n, m, NY[N]; 
int main() {
	scanf("%d%d", &n, &m);
	NY[1] = 1;
	L(i, 2, max(n, m) + 1) NY[i] = 1ll * NY[mod % i] * (mod - mod / i) % mod;
	int ans = 0;
	L(i, 1, n) (ans += NY[i]) %= mod;
	ans = 1ll * ans * m % mod * (n + m + 1) % mod;
	(ans += n + m + 1) % mod;
	ans = 1ll * ans * NY[m + 1] % mod; 
	printf("%d\n", ans);
	return 0;
}