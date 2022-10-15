// ./c-product-1-modulo-n.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    vector<int> ans;
    ll cmod = 1;
    for (auto i = 1; i <= N; i++) {
        if (gcd(i, N) == 1) {
            ans.push_back(i);
            cmod = (cmod * i) % N;
        }
    }

    if (cmod == 1) {
        cout << ans.size() << '\n';
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }
    else {
        cout << ans.size()-1 << '\n';
        for (auto x : ans)
            if (x != cmod)
                cout << x << ' ';
        cout << '\n';
    }

    return 0;
}