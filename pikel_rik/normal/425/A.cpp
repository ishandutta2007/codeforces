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

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> neg;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0)
            neg.push_back(i);
    }

    k = min(k, (int)neg.size());

    if (n == neg.size()) {
        cout << *max_element(all(a)) << "\n";
        return 0;
    }

    if (neg.size() == 0) {
        cout << accumulate(all(a), 0) << "\n";
        return 0;
    }

    multiset<int, greater<>> s;
    for (int i : a) s.insert(i);

    int best = 0;
    for (int i = 0; i < n; i++) {
        multiset<int> neg;

        int sum = 0;

        for (int j = i; j < n; j++) {
            if (a[j] < 0)
                neg.insert(a[j]);
            sum += a[j];
            s.erase(s.find(a[j]));
            int c = 0, sum1 = sum;

            auto it1 = neg.begin(), it2 = s.begin();
            while (c < k and it1 != neg.end() and it2 != s.end()) {
                if (*it2 <= 0) break;
                sum1 -= *it1;
                sum1 += *it2;
                c++; it1++; it2++;
            }
            best = max(best, sum1);
        }

        s.clear();
        for (int x : a) s.insert(x);
    }

    cout << best << "\n";
    return 0;
}