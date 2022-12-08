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

const int N = 110;

int n, s1[N], s2[N], p[N];

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cout << "? ";
		for (int j = 1; j < n; j++)
			cout << "1 ";
		cout << i + 1 << endl;
		cout.flush();
		cin >> s2[i];
	}
	for (int i = 1; i < n; i++) {
		cout << "? ";
		for (int j = 1; j < n; j++)
			cout << i + 1 << " ";
		cout << 1 << endl;
		cout.flush();
		cin >> s1[i];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (s1[i]) cnt++;
	for (int i = cnt; i >= 1; i--)
		p[s1[i]] = cnt - i + 1;
	p[n] = cnt + 1;
	for (int i = 1; i <= n - cnt - 1; i++)
		p[s2[i]] = cnt + 1 + i;
	cout << "! ";
	for (int i = 1; i <= n; i++)
		cout << p[i] << " ";
	cout << endl;
	return 0;
}