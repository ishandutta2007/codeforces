#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 2e5 + 10, P = 998244353;

int n, k, a[N];

int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	print(1ll * (2 * n - k + 1) * k / 2, ' ');
	ll ans = 1, lst = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] >= n - k + 1) {
			if (lst) (ans *= i - lst) %= P;
			lst = i;
		}
	print(ans, '\n');
	return 0;
}