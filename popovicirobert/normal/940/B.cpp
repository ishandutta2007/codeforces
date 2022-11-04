#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 206
// 44

using namespace std;

multiset < pair <ll, int> > mst;
multiset < pair <ll, int> > :: iterator it;

map <int, bool> dst;

int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, n, k, a, b;
    ios::sync_with_stdio(false);
    cin >> n >> k >> a >> b;
    if(k == 1) {
        cout << 1LL * (n - 1) * a;
        return 0;
    }
    ll ans = 0;
    while(n > 1) {
        ll cst = min(1LL * b, 1LL * ((n / k) * k - (n / k)) * a);
        if(n < k)
            ans += 1LL * (n % k - 1) * a;
        else
            ans += 1LL * (n % k) * a + cst;
        n /= k;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}