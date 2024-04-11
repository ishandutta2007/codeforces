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
const int G = 19260817;
const int mod = 998244353;
int n, now = -1, ans[N], has[N], Pow[N];
char s[N];
bool pd(int l1, int l2, int len) {
	if(l1 > l2) swap(l1, l2);
	return 1ll * (has[l1 + len - 1] - has[l1 - 1] + mod) % mod * Pow[l2 - l1] % mod == (has[l2 + len - 1] - has[l2 - 1] + mod) % mod;
}
int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	Pow[0] = 1;
	L(i, 1, n) Pow[i] = 1ll * Pow[i - 1] * G % mod;
	L(i, 1, n) has[i] = (has[i - 1] + 1ll * Pow[i] * (s[i] - 'a' + 1) % mod) % mod;
	if(n % 2) now -= 2;
	R(i, (n + 1) / 2, 1) {
		now += 2;
		while(now > 0 && !pd(i, n - i + 1 - now + 1, now)) now -= 2;
		ans[i] = now;
	}
	L(i, 1, (n + 1) / 2) printf("%d ", ans[i]);
	puts("");
	return 0;
}