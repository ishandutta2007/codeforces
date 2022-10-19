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

const int M = 510;

int l[M], p[M];
string s;

int cmp(int x, int y) {
	return l[x] < l[y];
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		s += '0';
	for (int i = 0; i < m; i++) {
		s[i] = '1';
		cout << "? " << s << endl;
		cout.flush();
		cin >> l[i];
		s[i] = '0';
		p[i] = i;
	}
	sort (p, p + m, cmp);
	int ans = 0, tans;
	for (int i = 0; i < m; i++) {
		s[p[i]] = '1';
		cout << "? " << s << endl;
		cout.flush();
		cin >> tans;
		if (tans == ans + l[p[i]])
			ans = tans;
		else s[p[i]] = '0';
	}
	cout << "! " << ans << endl;
	return 0;
}