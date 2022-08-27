#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 5e5 + 7;
int T, n, m;
ll a[N], b[N], c[N];
void Main() {
	scanf("%d%d", &n, &m);
	L(i, 1, n) scanf("%lld", &a[i]), c[i] = abs(a[i] - a[i - 1]);
	L(i, 1, m) scanf("%lld", &b[i]);
	ll GCD = c[2];
	L(i, 3, n) GCD = __gcd(GCD, c[i]);
	L(i, 1, m) printf("%lld ", __gcd(GCD, a[1] + b[i]));
}
int main() {
	Main();
	return 0;
}