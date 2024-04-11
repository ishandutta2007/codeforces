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

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();

    cout.precision(10);
    double probability;

    int pos = 0, pos1 = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] == '+')
            pos += 1;
        else
            pos -= 1;
        if (s2[i] == '+')
            pos1 += 1;
        else if (s2[i] == '-')
            pos1 -= 1;
        else
            c += 1;
    }

    int ans = pos - pos1;
    if ((c - abs(ans)) % 2 != 0 or abs(ans) > c)
        cout << 0;
    else {
        int n1 = (c - abs(ans)) / 2, n2 = abs(ans) + (c - abs(ans)) / 2;

        memset(dp, -1, sizeof(dp));
        cout << (double)choose(c, n1) / pow(2, c);
    }
    return 0;
}