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

vector <int> a, b, c;
int na, nb, nc, x;
ll ans = 0x3f3f3f3f3f3f3f3f;

void calc() {
	for (int v : a) {
		auto it = lower_bound(b.begin(), b.end(), v);
		vector <int> t2, t3;
		if (it != b.end()) t2.push_back(*it);
		if (it != b.begin()) t2.push_back(*(--it));
		it = lower_bound(c.begin(), c.end(), v);
		if (it != c.end()) t3.push_back(*it);
		if (it != c.begin()) t3.push_back(*(--it));
		for (int v2 : t2) for (int v3 : t3)
			ans = min(ans, 1ll * (v - v2) * (v - v2) + 1ll * (v - v3) * (v - v3) + 1ll * (v2 - v3) * (v2 - v3));
	}
}

int main() {
	int T;
	for (read(T); T; T--) {
		a.clear(), b.clear(), c.clear();
		ans = 0x3f3f3f3f3f3f3f3f;
		read(na), read(nb), read(nc);
		for (int i = 0; i < na; i++) {
			read(x); a.push_back(x);
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < nb; i++) {
			read(x); b.push_back(x);
		}
		sort(b.begin(), b.end());
		for (int i = 0; i < nc; i++) {
			read(x); c.push_back(x);
		}
		sort(c.begin(), c.end());
		calc();
		swap(a, b), swap(na, nb);
		calc();
		swap(a, c), swap(na, nc);
		calc();
		print(ans, '\n');
	}
	return 0;
}