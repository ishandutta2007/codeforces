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

int n, q, cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    multiset<int, greater<>> s;
    for (int i = 1; i < N; i++) {
        if (cnt[i])
            s.insert(cnt[i]);
    }

    cin >> q;
    while (q--) {
        char c;
        cin >> c;

        int x;
        cin >> x;

        if (c == '+') {
            if (cnt[x])
                s.erase(s.find(cnt[x]));
            cnt[x]++;
            s.insert(cnt[x]);
        }
        else {
            s.erase(s.find(cnt[x]));
            cnt[x]--;
            if (cnt[x])
                s.insert(cnt[x]);
        }

        int mx1 = (s.size() > 0 ? *s.begin() : 0), mx2 = (s.size() > 1 ? *(++s.begin()) : 0), mx3 = (s.size() > 2 ? *(++(++s.begin())) : 0);

        if (mx1 >= 8 or (mx1 >= 6 and mx2 >= 2) or (mx1 >= 4 and mx2 >= 4) or (mx1 >= 4 and mx2 >= 2 and mx3 >= 2)) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
    return 0;
}