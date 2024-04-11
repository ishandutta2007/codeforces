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

const int N = 1e5 + 10;

int T, a[N], b[N];
priority_queue <int, vector <int>, greater <int> > q1, q2;

int main() {
	ios::sync_with_stdio(false);
	for (cin >> T; T; T--) {
		while (q1.size()) q1.pop();
		while (q2.size()) q2.pop();
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		sort (a + 1, a + n + 1);
		sort (b + 1, b + n + 1);
		int k = n - n / 4, s1 = 0, s2 = 0;
		for (int i = 1; i <= k; i++) {
			int x = a[n - i + 1];
			q1.push(x), s1 += x;
		}
		for (int i = 1; i <= k; i++) {
			int x = b[n - i + 1];
			q2.push(x), s2 += x;
		}
		int ans = 0;
		for (ans = 0; ; ans++) {
			if (s1 >= s2) {
				cout << ans << endl;
				break;
			}
			int nn = n + ans + 1, k = nn - nn / 4;
			q1.push(100), s1 += 100;
			if (nn % 4 == 0){
				int x = q1.top(); q1.pop();
				s1 -= x;
			}
			if (k <= n) {
				if (nn % 4 == 0) continue;
				s2 += b[n - k + 1], q2.push(b[n - k + 1]);
			}
			else {
				if (nn % 4 != 0) {
					q2.push(0);
				}
			}
		}
	}
	return 0;
}