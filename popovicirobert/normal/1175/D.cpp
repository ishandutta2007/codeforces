#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    vector <ll> sp(n + 1);
    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sp[i] = sp[i - 1] + x;
    }

    sort(next(sp.begin()), prev(sp.end()));

    ll ans = 1LL * sp[n] * k;

    for(i = 1; i < k; i++) {
        ans -= sp[i];
    }

    cout << ans;

    //cin.close();
    //cout.close();
    return 0;
}