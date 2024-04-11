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
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

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

const int N = 1e6 + 10;

int n, a[N], st[N], top, cnt[N], b[N];
ll ans = 0;

int main() {
	read(n); lep (i, 1, n) read(a[i]);
	int Max = 0, pos = 0; ans = n - 1;
	lep (i, 1, n) if (a[i] > Max) Max = a[i], pos = i;
	lep (i, pos + 1, n) b[i - pos] = a[i];
	lep (i, 1, pos - 1) b[n - pos + i] = a[i];
	lep (i, 1, n - 1) {
		while (top && st[top] < b[i]) ans += cnt[top--];
		if (st[top] != b[i]) st[++top] = b[i], cnt[top] = 0;
		ans += cnt[top]++;
	}
	while (top > 1) ans += cnt[top--];
	print(ans, '\n');
	return 0;
}