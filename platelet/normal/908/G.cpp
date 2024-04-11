#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
typedef long long ll;
const ll P = 1e9 + 7;
int n, a[705]; char s[705];
ll Pow[705][11];
int main() {
	cin >> s, n = strlen(s);
	rep(i, 1, n) a[i] = s[n - i] - 48;
	int i = 1;
	while(a[i] == 9) a[i++] = 0;
	a[i]++; 
	if(i > n) n++;
	reverse(a + 1, a + n + 1);
	rep(i, 1, 10) Pow[0][i] = 1;
	rep(i, 1, n) rep(j, 1, 10) Pow[i][j] = Pow[i - 1][j] * (100 - 9 * j) % P;
	int idx[11] = {};
	ll as = 0;
	rep(i, 1, n) rep(j, 1, 9) {
		(as += Pow[idx[j]][10] * Pow[n - i][j] % P * (10 * max(a[i] - j, 0) + min(a[i], j)) - a[i] * Pow[n - i][10]) %= P;
		idx[j] += a[i] >= j;
	}
	cout << (as * 111111112 % P + P) % P;
	return 0;
}