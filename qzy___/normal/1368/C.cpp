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

int n;
vector <pii > vec;

int main() {
	read(n);
	int i = 1e8, j = 1;
	lep (k, 1, n) {
		vec.pb(mp(i, j));
		vec.pb(mp(i - 1, j));
		vec.pb(mp(i - 1, j - 1));
		vec.pb(mp(i, j - 1));
		vec.pb(mp(i + 1, j));
		vec.pb(mp(i, j + 1));
		vec.pb(mp(i, j + 2));
		if (k != n) i -= 2, j += 2;
	}
	lep (k, 1, j + 2) vec.pb(mp(1e8 + 2, k));
	rep (k, 1e8 + 1, i + 1) vec.pb(mp(k, j + 2));
	cout << vec.size() << endl;
	for (pii k : vec) cout << k.fi << " " << k.se << endl;
	return 0;
}