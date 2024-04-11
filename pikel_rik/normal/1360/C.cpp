#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> odd, even;
        for (int i : a) {
            if (i % 2) odd.push_back(i);
            else even.push_back(i);
        }

        if (odd.size() % 2 == 0 and even.size() % 2 == 0) {
            cout << "YES\n";
            continue;
        }

        if (odd.size() % 2 != even.size() % 2) {
            cout << "NO\n";
            continue;
        }

        sort(all(even));
        bool flag = false;

        for (int i : odd) {
            if (binary_search(all(even), i - 1) or binary_search(all(even), i + 1)) {
                cout << "YES\n";
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "NO\n";
    }
    return 0;
}