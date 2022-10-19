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

const int N = 1e5 + 10;;

int T, n;
ll f[N], v[N];

int main() {
	for (read(T); T; T--) {
		read(n);
		for (int i = 1; i <= n; i++)
			read(v[i]);
		if(n == 2) {
			print(1ll * n * (v[1] + v[2]), '\n');
		}
		else {
			ll Ans = 1ll * n * (v[1] + v[2]);
			ll Min[2] = {v[2], v[1]}, Sum[2] = {v[2], v[1]}, ct[2] = {1, 1};
			for (int i = 3; i <= n; i++) {
				ct[i % 2]++, Min[i % 2] = min(Min[i % 2], (ll)v[i]), Sum[i % 2] += v[i];
				Ans = min(Ans, Sum[0] + Sum[1] + (n - ct[0]) * Min[0] + (n - ct[1]) * Min[1]);
			}
			print(Ans, '\n');
		}
		
	}
	return 0;
}