#include <bits/stdc++.h>
#include <unordered_set>

#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

void solve() {
    int n, s; cin >> n >> s;
    ll su;
    cin >> su;
    ll ma = su; ll mai = 1;
    ll ans = 0;
    for(int i = 1; i < n; ++i){
        ll f; cin >> f;
        su += f;
        if (f > ma) {
            mai = i + 1;
        }
        ma = max(ma, f);
        if (su - ma <= s) {
            ans = mai;
        }
    }
    if (su <= s) {
        ans = 0;
    }
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tests;
    cin >> tests;
    //tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}