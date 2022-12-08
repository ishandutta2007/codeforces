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
inline void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
inline void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 1e6 + 10;

int T, n, C, a[N], c[N], s[N];

int main() {
	for (read(T); T; T--) {
		read(n), read(C);
		lep (i, 1, C) c[i] = s[i] = 0;
		lep (i, 1, n) read(a[i]), c[a[i]]++;
		lep (i, 1, C) s[i] = s[i - 1] + c[i];
		int flag = 1;
		lep (i, 1, C) if (c[i]) {
			for (int j = i; j <= C; j += i) {
				int k = min(j + i - 1, C);
				int sm = s[k] - s[j - 1];
				if (sm > 0 && c[j / i] == 0) flag = 0;
			}
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}