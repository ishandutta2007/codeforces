#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int N = 1e4 + 5;

int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(4 * n);
        for (int i = 0; i < 4 * n; i++) cin >> a[i], cnt[a[i]]++;

        sort(a.begin(), a.end());

        bool flag = true;
        set<int> areas;

        for (int i = 0, j = 4 * n - 2; i < 2 * n; i += 2, j -= 2) {
            if (a[i] != a[i + 1] or a[j] != a[j + 1]) {
                flag = false;
                break;
            }
            areas.insert(a[i] * a[j]);
        }

        cout << (flag and areas.size() == 1 ? "YES" : "NO") << '\n';
    }
    return 0;
}