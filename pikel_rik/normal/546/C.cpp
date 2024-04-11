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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    int k1; cin >> k1;
    deque<int> a(k1);
    for (int i = 0; i < k1; i++) cin >> a[i];

    int k2; cin >> k2;
    deque<int> b(k2);
    for (int i = 0; i < k2; i++) cin >> b[i];

    set<pair<deque<int>, deque<int>>> s;
    int c = 0;

    while (s.find({a, b}) == s.end() and !a.empty() and !b.empty()) {
        c += 1;
        s.insert({a, b});

        if (a.front() > b.front()) {
            a.push_back(b.front());
            a.push_back(a.front());
            a.pop_front(); b.pop_front();
        }
        else {
            b.push_back(a.front());
            b.push_back(b.front());
            b.pop_front(); a.pop_front();
        }
    }

    if (s.find({a, b}) != s.end()) {
        cout << "-1";
        return 0;
    }

    if (!a.empty()) {
        cout << c << " " << 1 << "\n";
        return 0;
    }

    if (!b.empty()) {
        cout << c << " " << 2 << "\n";
        return 0;
    }
    return 0;
}