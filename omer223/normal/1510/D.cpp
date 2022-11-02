#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e5 + 5;
int a[sz];
ld dp[sz][10];
int prv[sz][10][3];
const ld inf = 1e18;

int main() {
	fast;
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int j = 0; j < 10; j++) {
        dp[0][j] = -inf;
        prv[0][j][0] = prv[0][j][1] = -1;
        prv[0][j][2] = 0;
    }
    dp[0][a[0] % 10] = logl(a[0]);
    prv[0][a[0] % 10][0] = prv[0][a[0] % 10][1] = -1;
    prv[0][a[0] % 10][2] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = dp[i - 1][j];
            prv[i][j][0] = i - 1;
            prv[i][j][1] = j;
            prv[i][j][2] = 0;
        }
        int dig = a[i] % 10;
        if (dp[i][dig] < logl(a[i])) {
            dp[i][dig] = logl(a[i]);
            prv[i][dig][0] = prv[i][dig][1] = -1;
            prv[i][dig][2] = 1;
        }
        for (int j = 0; j < 10; j++) {
            if (dp[i][(dig * j) % 10] < dp[i - 1][j] + logl(a[i])) {
                dp[i][(dig * j) % 10] = dp[i - 1][j] + logl(a[i]);
                prv[i][(dig * j) % 10][0] = i - 1;
                prv[i][(dig * j) % 10][1] = j;
                prv[i][(dig * j) % 10][2] = 1;
            }
        }
    }
    if (dp[n - 1][d] < 0)cout << -1;
    else {
        vector<int> ret;
        int x = n - 1, y = d;
        while (x >= 0) {
            if (prv[x][y][2] == 1)ret.pb(a[x]);
            int tx = prv[x][y][0], ty = prv[x][y][1];
            x = tx;
            y = ty;
        }
        cout << ret.size() << '\n';
        for (int x : ret)cout << x << ' ';
    }
	return 0;
}