#include <bits/stdc++.h>
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;
using namespace std;
 
int n, k, M = 998244353;
ll dp[1001][2001][4];
 
ll solve(int i = 0, int r = 0, int lst = 0) {
    if (r > k) {
        return 0;
    }
    if (i == n) {
        return r == k;
    }
    ll& ret = dp[i][r][lst];
    if (~ret) {
        return ret;
    }
    ret = 0;
    if (i == 0) {
        ret += solve(i+1, r+2, 0)%M;
        ret += solve(i+1, r+2, 1)%M;
        ret += solve(i+1, r+1, 2)%M;
        ret += solve(i+1, r+1, 3)%M;
    } else {
        if (lst == 0) {
            ret += solve(i+1, r, 0)%M;
            ret += solve(i+1, r+2, 1)%M;
            ret += solve(i+1, r, 2)%M;
            ret += solve(i+1, r, 3)%M;
        } else if (lst == 1) {
            ret += solve(i+1, r+2, 0)%M;
            ret += solve(i+1, r, 1)%M;
            ret += solve(i+1, r, 2)%M;
            ret += solve(i+1, r, 3)%M;
        } else if (lst == 2) {
            ret += solve(i+1, r+1, 0)%M;
            ret += solve(i+1, r+1, 1)%M;
            ret += solve(i+1, r, 2)%M;
            ret += solve(i+1, r+1, 3)%M;
        } else {
            ret += solve(i+1, r+1, 0)%M;
            ret += solve(i+1, r+1, 1)%M;
            ret += solve(i+1, r+1, 2)%M;
            ret += solve(i+1, r, 3)%M;
        }
    }
    return ret%M;
}
int main() {
    IOS
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    cout << solve() << endl;
}