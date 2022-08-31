#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int dp[11][11];

double choose(int n, int r) {
    if (r == 0)
        return 1;
    if (n == r)
        return 1;
    if (dp[n][r] != -1)
        return dp[n][r];
    return dp[n][r] = choose(n - 1, r - 1) + choose(n - 1, r);
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll cost = 0, c = 0, c_0 = 0;
    for (int i = 0; i < n; i++) {
        cost += abs(abs(a[i]) - 1);
        if (a[i] <= -1)
            c += 1;
        if (a[i] == 0)
            c_0 += 1;
    }

    if (c % 2 != 0 and c_0 == 0)
        cout << cost + 2;
    else
        cout << cost;
    return 0;
}