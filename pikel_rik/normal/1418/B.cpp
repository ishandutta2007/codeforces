#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), l(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> l[i];

        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (!l[i]) {
                temp.push_back(a[i]);
            }
        }
        sort(temp.begin(), temp.end(), greater<>());
        int ptr = 0;

        for (int i = 0; i < n; i++) {
            if (!l[i]) {
                a[i] = temp[ptr++];
            }
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}