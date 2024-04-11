#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, d, m, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> les(1), grt(1);
    for (int i = 0; i < n; i++) {
        if (a[i] <= m)
            les.push_back(a[i]);
        else grt.push_back(a[i]);
    }

    sort(1 + all(les));
    sort(1 + all(grt), greater<>());

    for (int i = 1; i < les.size(); i++) {
        les[i] += les[i - 1];
    }
    for (int i = 1; i < grt.size(); i++) {
        grt[i] += grt[i - 1];
    }

    ll ans = les.back();
    for (int i = 1; i < grt.size(); i++) {
        if (i + (i - 1) * (ll)d > n)
            break;

        int lost = grt.size() - i - 1, req = (i - 1) * d;

        ll sum = 0;
        if (req >= lost) {
            req -= lost;
            sum = les.back() - les[req] + grt[i];
        }
        else {
            lost -= req;
            if (lost <= d) {
                sum = les.back() + grt[i];
            }
        }
        ans = max(ans, sum);
    }

    cout << ans << "\n";
    return 0;
}