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

ll t;
string s = "codeforces";

int main() {
	read(t); ll x;
	if (t == 1) {
		cout << s << endl;
		return 0;
	}
	for (x = 1; ; x++) {
		ll tmp = 1;
		for (int i = 1; i <= 10; i++)
			tmp *= x;
		if (tmp >= t) break;
	}
	ll tmp = 1; x--;
	for (int i = 1; i <= 10; i++)
		tmp *= x;
	for (int i = 1; i <= 10; i++) {
		int temp = x;
		if (tmp < t) tmp /= x, tmp *= x + 1, temp++;
		for (int j = 1; j <= temp; j++)
			cout << s[i - 1];
	}
	cout << endl;
	return 0;
}