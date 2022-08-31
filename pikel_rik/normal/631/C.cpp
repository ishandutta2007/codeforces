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
const int N = 2e5 + 5;

int n, m, a[N], r[N], t[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> q;
    for (int i = 0; i < m; i++) {
        cin >> t[i] >> r[i];
        q.push({r[i], i});
    }

    multiset<int> s;
    for (int i = 0; i < n; i++) s.insert(a[i]);

    int i = 0;
    while (!q.empty()) {
        while (!q.empty() and q.top().second < i)
            q.pop();

        int len = q.top().first;
        i = q.top().second;
        q.pop();

        while (s.size() > len) {
            s.erase(s.find(a[s.size() - 1]));
        }

        while (!q.empty() and q.top().second < i)
            q.pop();

        if (q.empty()) {
            int c = 0;
            for (int x : s)
                a[c++] = x;
            if (t[i] == 2)
                reverse(a, a + len);
            break;
        }

        int new_len = q.top().first;
        while (len > new_len) {
            if (t[i] == 1) {
                a[len-1] = *(s.rbegin());
                s.erase(s.find(*s.rbegin()));
            }
            else {
                a[len-1] = *s.begin();
                s.erase(s.begin());
            }
            len -= 1;
        }
    }

    for (int j = 0; j < n; j++) {
        cout << a[j] << " ";
    }

    return 0;
}