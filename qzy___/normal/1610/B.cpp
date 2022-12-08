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

const int N = 2e5 + 10;

int T, n, a[N];

int check(int x) {
	int flag = 1;
	for (int l = 1, r = n; l < r; l++, r--) {
		while (l <= n && a[l] == x) l++;
		while (r >= 1 && a[r] == x) r--;
		if (l > r) break;
		if (a[l] != a[r]) {
			flag = 0;
			break;
		}
	}
	return flag;
}

int main() {
	for (read(T); T; T--) {
		read(n);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		int flag = 1, ans = 0;
		for (int i = 1, j = n; i <= j; i++, j--)
			if (a[i] != a[j]) {
				ans = check(a[i]) | check(a[j]);
				flag = 0;
				break;
			}
		puts((ans | flag) ? "YES" : "NO");
	}
	return 0;
}