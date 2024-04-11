#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

const ll inf = 1e18;

ll n, m, k, a, b;

int main(){
    //ifstream cin("tetris.dat");
    //ofstream cout("tetris.sol");
    ios::sync_with_stdio(0);
    cin >> n >> m >> k >> a >> b;
    ll ans = 0;
    ll p1, p2, l1, l2;
    if (a % (m * k) > 0)
        p1 = a / (m * k), a %= m * k, l1 = (a - 1) / k;
    else
        p1 = a / (m * k) - 1, l1 = m - 1;
    if (b % (m * k) > 0)
        p2 = b / (m * k), b %= m * k, l2 = (b - 1) / k;
    else
        p2 = b / (m * k) - 1, l2 = m - 1;
    ans = min(abs(p1 - p2), n - abs(p1 - p2)) * 15;
    if (p1 != p2)
        ans += min(l1 * 5, 10 + l1),
        ans += min(l2 * 5, 10 + l2);
    else
        ans += min(abs(l1 - l2) * 5, 10 + abs(l1 - l2));
    cout << ans;
}