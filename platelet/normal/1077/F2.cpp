#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 5e3 + 5;

int n, k, m, a[N], q[N];
ll f[N][N];

int main() {
    cin >> n >> k >> m;
    rep(i, 1, n) scanf("%d", &a[i]);
    mem(f, 192), f[0][0] = 0;
    rep(i, 1, m + 1) {
        int l = 1, r = 1; q[1] = 0;
        rep(j, 1, n + 1) {
            while(q[l] < j - k) l++;
            f[i][j] = f[i - 1][q[l]] + a[j];
            while(l <= r && f[i - 1][q[r]] <= f[i - 1][j]) r--;
            q[++r] = j;
        }
    }
    cout << max(f[m + 1][n + 1], -1ll);
}