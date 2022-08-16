#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, f, s;
    cin >> n >> m >> s >> f;

    int cur = s;

    vector<pair<int, pair<int, int>>> watch;
    for (int i = 0; i < m; i++) {
        int l, r, t;
        cin >> t >> l >> r;

        watch.push_back({t, {l, r}});
    }

    int ptr = 0;
    for (int t = 1; cur != f; t++) {
        if (ptr < m and t == watch[ptr].first) {
            int l = watch[ptr].second.first, r = watch[ptr].second.second;
            if (cur < f) {
                if (cur + 1 < l or cur > r) {
                    cur += 1;
                    cout << 'R';
                }
                else cout << 'X';
            }
            else if (cur > f) {
                if (cur < l or cur - 1 > r) {
                    cur -= 1;
                    cout << 'L';
                }
                else cout << 'X';
            }
            ptr += 1;
        }
        else {
            if (cur < f) {
                cur += 1;
                cout << 'R';
            }
            else if (cur > f) {
                cur -= 1;
                cout << 'L';
            }
        }
    }
    return 0;
}