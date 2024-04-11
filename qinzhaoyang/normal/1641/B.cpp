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

const int N = 510;

int T, n, a[N];
map <int,int> mp1;

int main() {
	for (read(T); T; T--) {
		mp1.clear();
		read(n);
		for (int i = 1; i <= n; i++)
			read(a[i]), mp1[a[i]]++;
		int flag = 0;
		for (pii pr : mp1)
			if (pr.second & 1) flag = 1;
		if (flag == 1) {
			puts("-1");
			continue;
		}
		vector <int> v, ans2, vn;
		vector <pii > ans1;
		for (int i = 1; i <= n; i++)
			v.pb(a[i]);
		int s = 0;
		while (v.size()) {
			int p = 0;
			for (int i = 1; i < v.size(); i++)
				if (v[i] == v[0]) p = i;
			for (int i = 1; i < p; i++)
				ans1.pb(mp(s + p + i, v[i]));
			vn.clear();
			for (int i = p - 1; i >= 1; i--)
				vn.push_back(v[i]);
			for (int i = p + 1; i < v.size(); i++)
				vn.push_back(v[i]);
			v = vn;
			ans2.push_back(2 * p);
			s += 2 * p;
		}
		print((int)ans1.size(), '\n');
		for (pii pr : ans1)
			print(pr.first, ' '), print(pr.second, ' ' );
		puts("");
		print((int)ans2.size(), '\n');
		for (int x : ans2)
			print(x, ' ');
		puts("");
	}
	return 0;
}