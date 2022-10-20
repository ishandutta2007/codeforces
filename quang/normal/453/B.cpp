#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 110;
const int amax = 58;
const int MAX = 123456789;

int n, a[N], d;
int snt[20], thuaso[60];
int dp[N][1 << 16], t[N][1 << 16];

bool KT(int x) {
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i <= amax; i++)
    if(KT(i)) snt[d++] = i;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 1 << d; j++) dp[i][j] = MAX;
    dp[0][0] = 0;
    for(int i = 1; i <= amax; i++)
    for(int j = 0; j < d; j++)
        if(i % snt[j] == 0) thuaso[i] |= (1 << j);
    for(int i = 1; i <= n; i++)
    for(int j = 0; j < (1 << d); j++)
    for(int x = 1; x <= amax; x++)
    if(!(j & thuaso[x])) {
        int cauhinh = j | thuaso[x];
        if(dp[i][cauhinh] > dp[i - 1][j] + abs(x - a[i])) {
            dp[i][cauhinh] = dp[i - 1][j] + abs(x - a[i]);
            t[i][cauhinh] = x;
        }
    }
    vector <int> b(n + 1, 0);
    int ans = MAX, cauhinh;
    for(int i = 0; i < (1 << d); i++)
    if(ans > dp[n][i]) {
        ans = dp[n][i];
        cauhinh = i;
    }
    for(int i = n; i; i--) {
        b[i] = t[i][cauhinh];
        cauhinh = cauhinh ^ thuaso[b[i]];
    }
    for(int i = 1; i <= n; i++) cout << b[i] << " " ;
    return 0;
}