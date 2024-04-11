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

int n, need[1010], now[1010];

int main() {
	cin >> n;
	if (n <= 3) {
		cout << 0 << endl;
		return 0;
	}
	int Max = 0, k = 0;
	for (int i = 2; i < n; i++) {
		int t = (n - 1) / i;
		int tmp = (t - 1) * (i - 1) + (n - 1 - t * i);
		if (tmp > Max) Max = tmp, k = i;
	}
	for (int j = 2, o = j + k - 1; j <= n; j += k, o += k) {
		if (o <= n) {
			for (int s = j; s < o; s++) need[s] = 1;
		}
		else {
			for (int s = j; s <= n; s++) need[s] = 1;
		}
	}
	while (true) {
		vector <int> x; int temp = 0;
		for (int i = 1; i <= n; i++) {
			if (need[i] && !now[i])
				x.push_back(i), now[i] = 1, temp++;
			if (temp == k) break;
		}
		cout << k << endl;
		for (int i : x) cout << i << " ";
		cout.flush();
		int s; cin >> s;
		int flag = 1;
		for (int i = 1; i <= n; i++)
			if (need[i] && !now[i]) flag = 0;
		if (flag) return cout << 0 << endl, cout.flush(), 0;
		for (int i = s; i <= s + k - 1; i++) {
			if (i <= n) now[i] = 0;
			else now[i - n] = 0;
		}
	}
	return 0;
}