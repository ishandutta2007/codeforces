#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

ll solve(ll l, ll r, int bit) {
    if(bit == -1)
        return 0;
    if(l + (1LL << bit) <= r) {
        return solve(l + (1LL << bit), r, bit - 1) + 1LL * bit * (1LL << (bit - 1)) + (1LL << bit);
    }
    return solve(l, r, bit - 1);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    ll n;
    ios::sync_with_stdio(false);
    cin >> n;
    cout << solve(0, n - 1, 50);
    //cin.close();
    //cout.close();
    return 0;
}