#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e3 + 7;
const int mod = 1e9 + 7;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar();
	return x * f;
}
int n, m, T;
int Sum(int l, int r) {
	return (ll) (r - l + 1) * (l + r) / 2 % mod;
}
int Get(int l1, int r1, int l2, int r2, int k) {
	if(r1 - l1 < r2 - l2) swap(l1, l2), swap(r1, r2);
	// r1 - l1 > r2 - l2
	int mn = (l1 ^ l2), len = r1 - l1;
	mn ^= (mn & (len - 1));
	// (mn + 1 ~ mn + len) * (r2 - l2)
	if(k <= mn) return 0;
	// cout << l1 << " " << r1 - 1 << ", " << l2 << " " << r2 - 1 << " : " << mn + 1 << " to " << mn + len << endl;
	return (ll) (r2 - l2) * Sum(mn + 1, min(k, mn + len)) % mod;
}
int work(int x, int y, int k) {
	int res = 0;
	for(int i = x; i; i -= (i & -i)) for(int j = y; j; j -= (j & -j)) (res += Get(i - (i & -i), i, j - (j & -j), j, k)) %= mod;
	return res;
}
void Main() {
	int l1 = read(), l2 = read(), r1 = read(), r2 = read(), k = read();
	printf("%d\n", ((work(r1, r2, k) - work(l1 - 1, r2, k) - work(r1, l2 - 1, k)
	 + work(l1 - 1, l2 - 1, k)) % mod + mod) % mod);
}
int main() {
	T = read();
	while(T--) Main();
	return 0;
}