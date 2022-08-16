#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, a[N];
map<int, vector<int>> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]].push_back(i);
    }

    sort(a, a + n);

    vector<int> ans1, ans2;
    int sum1 = 0, sum2 = 0;

    for (const auto &p : m) {
        if (p.second.size() % 2 == 0) {
            sum1 += p.first * p.second.size() / 2;
            sum2 += p.first * p.second.size() / 2;
            for (int i = 0; i < p.second.size(); i++) {
                if (i & 1) ans1.push_back(p.second[i]);
                else ans2.push_back(p.second[i]);
            }
        }
        else {
            if (ans1.size() <= ans2.size()) {
                for (int i = 0; i < p.second.size(); i++) {
                    if (i & 1) ans2.push_back(p.second[i]);
                    else ans1.push_back(p.second[i]);
                }
            }
            else {
                for (int i = 0; i < p.second.size(); i++) {
                    if (i & 1) ans1.push_back(p.second[i]);
                    else ans2.push_back(p.second[i]);
                }
            }
        }
    }

    cout << ans1.size() << "\n";
    for (int i : ans1) cout << i + 1 << " ";

    cout << "\n" << ans2.size() << "\n";
    for (int i : ans2) cout << i + 1 << " ";

    cout << "\n";
    return 0;
}