#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(X) (X).begin(), (X).end()
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;

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

const int N = 5e4 + 10;

int T, n, m, k, a[N], b[N], mn[N], ct[N];

int main() {
	for (read(T); T; T--) {
		read(n), read(m);
		for (int i = 1; i <= n; i++) {
			read(a[i]);
			mn[i] = a[i], ct[i] = 1;
			while (mn[i] % m == 0)
				mn[i] /= m, ct[i] *= m;
		}
		read(k);
		for (int i = 1; i <= k; i++)
			read(b[i]);
		vector<pair<ll,ll> >v;
		for (int i = 1; i <= n; i++) {
			if (!v.size() || v.back().first != mn[i])
				v.push_back(make_pair(mn[i], ct[i]));
			else
				v.back().se += ct[i];
		}
		reverse(v.begin(), v.end());
		map <ll, int> ok;
		ll tmp = m; ok[tmp] = 1;
		ok[1] = 1;
		while (tmp * m <= 1e9)
			tmp *= m, ok[tmp] = 1;
		int flag = 1;
		for (int i = 1; i <= k; i++) {
			if (!v.size()) {
				flag = 0;
				break;
			}
			if (b[i] % v.back().fi != 0) {
				flag = 0;
				break;
			}
			if (b[i] / v.back().fi > v.back().se) {
				flag = 0;
				break;
			}
			if (!ok[b[i] / v.back().fi]) {
				flag = 0;
				break;
			}
			v.back().se -= b[i] / v.back().fi;
			while (v.back().se == 0) v.pop_back();
		}
		if (v.size() > 0) flag = 0;
		puts(flag ? "Yes" : "No");
	}
	return 0;
}