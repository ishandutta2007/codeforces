#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;

int n;
int cnt[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) {
            int u; cin >> u;
            cnt[u]++;
        }
        vector<int> ls;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > 0) ls.push_back(cnt[i]);
        }
        int minVal = *min_element(ls.begin(), ls.end());
        int res = n;
        for (int i = 2; i <= minVal + 1; i++) {
            int found = 0;
            int tot = 0;
            for (int u : ls) {
                if (u % i == 0) {
                    tot += u / i;
                    continue;
                }
                int q = u / (i - 1);
                int mod = u % (i - 1);
                if (mod > q) {
                    found = 1;
                    break;
                }
                int x = mod;
                int y = q - mod;
                int delta = y / i;
                x += delta * (i - 1);
                y -= delta * i;
                tot += x + y;
            }
            if (!found) res = min(res, tot);
        }
        cout << res << '\n';
    }
    return 0;
}