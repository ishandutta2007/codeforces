#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;
    // (a, ~a), (b, ~b)
    // (a, b), (~a, ~b), ans += (a & b) + (~a & ~b) -> ~(a ^ b)
    // 0, ~(a ^ b) = k, a ^ b = ~k, b = a ^ ~k, b = ~k

    auto get_not = [&](int x) {
        return (~x) & (n-1);
    };
    if (k == 0) {
        for (int i = 0; i < n; i++) {
            int a = i, b = get_not(i);
            if (a < b) cout << a << ' ' << b << '\n';
        }
        return;
    }


    vector<pair<int, int>> ans;
    vector<bool> use(n);

    if (k == n-1) {
        if (n == 4) {
            cout << -1 << '\n';
            return;
        }
        {
            int a = 0, b = k ^ 1;
            use[a] = use[b] = 1;
            ans.emplace_back(a, b);

            use[get_not(a)] = use[get_not(b)] = 1;
            ans.emplace_back(get_not(a), get_not(b));

            k ^= 1;
        }
        {
            int a = 2, b = a ^ get_not(k);
            use[a] = use[b] = 1;
            ans.emplace_back(a, b);

            use[get_not(a)] = use[get_not(b)] = 1;
            ans.emplace_back(get_not(a), get_not(b));
        }
    } else {
        int a = 0, b = get_not(k);
        ans.emplace_back(a, b);
        use[a] = use[b] = 1;
        ans.emplace_back(get_not(a), get_not(b));
        use[get_not(a)] = use[get_not(b)] = 1;
    }

    for (int i = 0; i < n; i++) if (!use[i]) {
        ans.emplace_back(i, get_not(i));
        use[i] = use[get_not(i)] = 1;
    }

    for (auto [a, b] : ans) cout << a << ' ' << b << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}