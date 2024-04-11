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

        vector<int> a(n);
        for (auto& i : a) cin >> i;

        vector<int> pos, neg;
        for (auto& i : a) {
            if (i < 0)
                neg.push_back(i);
            else pos.push_back(i);
        }

        sort(pos.begin(), pos.end(), greater<>());
        sort(neg.begin(), neg.end());

        ll ans = LLONG_MIN;
        for (int i = 0; i <= 5; i++) {
            if (neg.size() < i or pos.size() < 5 - i)
                continue;
            ll temp = 1;
            if (i & 1) {
                for (int j = neg.size() - 1; j >= (int)neg.size() - i; j--) {
                    temp *= neg[j];
                }
                for (int j = pos.size() - 1; j >= (int)pos.size() - (5 - i); j--) {
                    temp *= pos[j];
                }
            } else {
                for (int j = 0; j < i; j++) {
                    temp *= neg[j];
                }
                for (int j = 0; j < 5 - i; j++) {
                    temp *= pos[j];
                }
            }
            ans = max(ans, temp);
        }

        cout << ans << '\n';
    }
    return 0;
}