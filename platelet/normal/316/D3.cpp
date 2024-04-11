#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int P = 1e9 + 7;
int n, f[1000005];
int main() {
    cin >> n;
    f[0] = f[1] = 1;
    int t, cnt = 0;
    rep(i, 1, n) scanf("%d", &t), cnt += 2 - t;
    rep(i, 1, cnt) f[i+1] = (f[i] + 1LL * i * f[i-1]) % P;
    rep(i, cnt + 1, n) f[cnt] = 1LL * f[cnt] * i % P;
    cout << f[cnt];
	return 0;
}