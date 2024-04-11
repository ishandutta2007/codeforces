#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const int maxB = 1000;
int cost[maxB + 1];

void solve() {
    //1 -> 2 (x = 1) -> 4 (x = 1) -> 8 (x = 1)
    int n, k;
    cin >> n >> k;
    vector<int> b(n), c(n);
    foru(i, 0, n)cin >> b[i];
    foru(i, 0, n)cin >> c[i];
    //dp[i][j] = best coins for items [0...i] with j operations
    int sum = 0;
    foru(i, 0, n)sum += cost[b[i]];
    k = min(k, sum); 
    // O(nk) = O(n2*maxcost)
    vector<int> dp(k + 1, 0), prv(k + 1, 0);
    foru(j, 0, k + 1) {
        if (j < cost[b[0]])
            dp[j] = 0;
        else dp[j] = c[0];
    }
    foru(i, 1, n) {
        prv = dp;
        foru(j, 0, k + 1)
            dp[j] = 0;
        foru(j, 0, k + 1) {
            dp[j] = prv[j];
            if (j >= cost[b[i]])
                dp[j] = max(dp[j], prv[j - cost[b[i]]] + c[i]);
        }
    }
    cout << dp[k] << '\n';
}

void precompute() {
    cost[1] = 0;
    // 1 -> 2 = (1 + 1 / 1)
    // 2 -> 3 = (2 + 2 / 2), 4 = (2 + 2 / 1)
    // 3 -> 4 = (3 + 3 / 3), 6 = (3 + 3 / 1)
    foru(i, 2, maxB + 1)cost[i] = 1e9;
    foru(i, 1, maxB + 1) {
        foru(j, 1, i + 1) {
            int jump = i + i / j;
            if (jump <= maxB)
                cost[jump] = min(cost[jump], cost[i] + 1);
        }
    }
}

int main() {
    fast;
    precompute();
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}