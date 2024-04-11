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

int T, h, w;
int a[22][22];

int main() {
	for (cin >> T; T; T--) {
		cin >> h >> w; int flag = 0;
		for (int i = 1; i <= 20; i++)
			for (int j = 1; j <= 20; j++)
				a[i][j] = 0;
		if (h % 2 == 1 && w % 2 == 1) {
			for (int i = 1; i <= h; i++)
				for (int j = 1; j <= w; j++) {
					if (i == 1 || j == 1 || i == h || j == w) {
						if ((i + j) % 2 == 0) a[i][j] = 1;
					}
				}
		}
		else if (h % 2 == 0 && w % 2 == 0) {
			for (int i = 2; i < w; i += 2)
				a[1][i] = 1;
			for (int j = 2; j < h; j += 2)
				a[j][w] = 1;
			for (int i = w - 1; i > 1; i -= 2)
				a[h][i] = 1;
			for (int j = h - 1; j > 1; j -= 2)
				a[j][1] = 1;
		}
		else {
			if (h % 2 == 0) flag = 1, swap(h, w);
			for (int i = 2; i <= w; i += 2)
				a[1][i] = 1;
			for (int j = 1; j < h; j += 2)
				a[j][w] = 1;
			for (int i = w - 1; i >= 1; i -= 2)
				a[h][i] = 1;
			for (int i = h; i > 1; i -= 2)
				a[i][1] = 1;
		}
		if (flag == 0) {
			for (int i = 1; i <= h; i++, cout << endl)
				for (int j = 1; j <= w; j++)
					cout << a[i][j];
		}
		else {
			for (int i = 1; i <= w; i++, cout << endl)
				for (int j = 1; j <= h; j++)
					cout << a[j][i];
		}
	}
	return 0;
}