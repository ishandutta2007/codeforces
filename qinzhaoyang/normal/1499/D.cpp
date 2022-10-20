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

ll Ans = 0;

const int N = 2e7 + 10;

int T, c, d, x, k[N], p[N], ct, f[N];
ll p2[61];

void Solve(int t) {
	int tmp = x / t + d;
	if (tmp % c) return;
	tmp /= c;
	Ans += p2[k[tmp]];
}

int main() {
	p2[0] = 1;
	for (int i = 1; i <= 30; i++)
		p2[i] = p2[i - 1] * 2;
	for (int i = 2; i <= 20000000; i++) {
		if (!f[i]) p[++ct] = i, k[i] = 1, f[i] = 1;
		for (int j = 1; i * p[j] <= 20000000 && j <= ct; j++) {
			f[i * p[j]] = 1;
			if (i % p[j] == 0)  {
				k[i * p[j]] = k[i];
				break;
			}
			k[i * p[j]] = k[i] + 1; 
		}
	}
	for (read(T); T; T--) {
		read(c), read(d), read(x), Ans = 0;
		for (int i = 1; i * i <= x; i++) if (x % i == 0) {
			if (i * i == x) Solve(i);
			else Solve(i), Solve(x / i);
		}
		print(Ans, '\n');
	}
	return 0;
}