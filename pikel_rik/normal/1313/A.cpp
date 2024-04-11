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
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];

        vector<int> v(7);
        iota(v.begin(), v.end(), 1);

        int ans = 0;
        do {
            int temp_ans = 0;
            vector<int> temp(a);

            for (int i : v) {
                if (i & 1 and temp[0] == 0) {
                    break;
                }
                if (i & 2 and temp[1] == 0) {
                    break;
                }
                if (i & 4 and temp[2] == 0) {
                    break;
                }

                for (int j = 0; j < 3; j++) {
                    if (i & (1 << j))
                        temp[j]--;
                }
                temp_ans++;
            }

            if (temp_ans != -1)
                ans = max(ans, temp_ans);
        } while (next_permutation(v.begin(), v.end()));

        cout << ans << '\n';
    }
    return 0;
}