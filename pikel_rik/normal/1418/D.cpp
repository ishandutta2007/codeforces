#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, q, p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);

    set<int>  s;
    for (int i = 0; i < n; i++) {
        s.insert(p[i]);
    }
    multiset<int> diff;
    for (int i = 1; i < n; i++) {
        diff.insert(p[i] - p[i - 1]);
    }

    if (s.empty() or diff.empty()) {
        cout << "0\n";
    } else cout << (*s.rbegin() - *s.begin()) - *diff.rbegin() << '\n';

    while (q--) {
        int t, x;
        cin >> t >> x;

        if (t == 0) {
            auto it = s.find(x);
            auto it1 = (it != s.begin() ? --it : s.end());
            if (*it != x) ++it;
            auto it2 = ++it;
            if (it1 != s.end()) {
                diff.erase(diff.find(x - *it1));
            }
            if (it2 != s.end()) {
                diff.erase(diff.find(*it2 - x));
            }
            if (it1 != s.end() and it2 != s.end()) {
                diff.insert(*it2 - *it1);
            }
            s.erase(s.find(x));
        } else {
            auto it = s.insert(x).first;
            auto it1 = (it != s.begin() ? --it : s.end());
            if (*it != x) ++it;
            auto it2 = ++it;
            if (it1 != s.end()) {
                diff.insert(x - *it1);
            }
            if (it2 != s.end()) {
                diff.insert(*it2 - x);
            }
            if (it1 != s.end() and it2 != s.end()) {
                diff.erase(diff.find(*it2 - *it1));
            }
        }

        if (s.empty() or diff.empty()) {
            cout << "0\n";
        } else {
            cout << (*s.rbegin() - *s.begin()) - *diff.rbegin() << '\n';
//            cout << *s.rbegin() << ' ' << *s.begin() << ' ' << *diff.rbegin() << '\n';
        }
    }
    return 0;
}