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

const int N = 1e5 + 10;

int n, q, ans = 0;
char s[N];

int main() {
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	for (int i = 1; i <= n - 2; i++)
		if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
			ans++;
	while (q--) {
		int p, c; scanf("%d %c", &p, &c);
		for (int i = p - 2; i <= p; i++)
			if (i >= 1 && i + 2 <= n)
				if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
					ans--;
		s[p] = c;
		for (int i = p - 2; i <= p; i++)
			if (i >= 1 && i + 2 <= n)
				if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
					ans++;
		print(ans, '\n');
	}
	return 0;
}