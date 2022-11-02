#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int T, n;
char s[N];

int main() {
	for(cin >> T; T--;) {
		scanf("%s", s + 1), n = strlen(s + 1);
		int j = 1, k = 1;
		ll as = 0;
		rep(i, 1, n) {
			int nj = s[i] != 49 ? k : i + 1, nk = s[i] != 48 ? j : i + 1;
			j = nj, k = nk, as += i - min(j, k) + 1;
			// cout << j << ' ' << k << endl;
		}
		printf("%lld\n", as);
	}
	return 0;
}