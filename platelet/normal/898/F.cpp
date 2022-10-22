#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
 
using namespace std;
const int N = 1e6 + 5, P = 999999937;
typedef long long ll;
int n; char s[N]; ll su[N], ten[N];
ll hsh(int l, int r) { return ((su[r] - su[l-1] * ten[r-l+1]) % P + P) % P; }
int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	rep(i, 1, n) su[i] = (su[i-1] * 10 + s[i] - 48) % P;
	ten[0] = 1; rep(i, 1, n) ten[i] = ten[i-1] * 10 % P;
	rep(i, 1, n - 2) {
		#define slv(a, b) \
		if(1 <= a && a < b && b < n && (1 == a || s[1] > 48) && (b - a == 1 || s[a+1] > 48) && (n - b == 1 || s[b+1]) && (hsh(1, a) + hsh(a + 1, b)) % P == hsh(b + 1, n)) {\
			rep(j, 1, a) putchar(s[j]); putchar('+');\
			rep(j, a + 1, b) putchar(s[j]); putchar('=');\
			rep(j, b + 1, n) putchar(s[j]);\
			return 0;\
		}
		slv(i, n - i); slv(i - 1, n - i); slv(n - i * 2, n - i); slv(n - i * 2 + 1, n - i);
	}
}