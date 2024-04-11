#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> sets(k);
        for (int i = 0; i < k; i++) {
            int sz; cin >> sz;
            sets[i].resize(sz);
            for (int j = 0; j < sz; j++) cin >> sets[i][j];
        }

        cout << "? " << n << " ";
        for (int i = 1; i <= n; i++) cout << i << " ";
        cout << "\n";
        cout.flush();

        int mx;
        cin >> mx;

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            cout << "? " << mid - lo + 1 << " ";
            for (int i = lo; i <= mid; i++) cout << i << " ";
            cout << "\n";
            cout.flush();

            int temp;
            cin >> temp;

            if (temp == mx)
                hi = mid;
            else lo = mid + 1;
        }

        int tar = -1;
        for (int i = 0; i < k && tar == -1; i++) {
            for (int j = 0; j < sets[i].size() && tar == -1; j++) {
                if (sets[i][j] == lo)
                    tar = i;
            }
        }

        string cor;

        if (tar == -1) {
            cout << "! ";
            for (int i = 0; i < k; i++) {
                cout << mx << " ";
            }

            cout << "\n";
            cout.flush();
            cin >> cor;

            if (cor == "Correct")
                continue;
            else return 0;
        }

        cout << "? " << n - sets[tar].size() << " ";
        set<int> s;
        for (int i : sets[tar]) s.insert(i);

        for (int i = 1; i <= n; i++) {
            if (s.find(i) == s.end()) cout << i << " ";
        }

        cout << "\n";
        cout.flush();

        int temp;
        cin >> temp;

        cout << "! ";
        for (int i = 0; i < k; i++) {
            if (i == tar) cout << temp << " ";
            else cout << mx << " ";
        }

        cout << "\n";
        cout.flush();

        cin >> cor;
        if (cor == "Correct")
            continue;
        else return 0;
    }
    return 0;
}