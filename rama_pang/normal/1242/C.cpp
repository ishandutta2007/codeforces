#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<vector<lint>> a(n);
    vector<lint> sum(n);
    map<lint, int> pos;
    lint target = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            lint b;
            cin >> b;
            a[i].emplace_back(b);
            sum[i] += b;
            pos[b] = i;
        }
        target += sum[i];
    }

    if (target % n != 0) {
        cout << "No\n";
        return 0;
    }
    target /= n;

    vector<vector<tuple<int, int, int>>> ans(1 << n); // (from, val, to)
    vector<int> masks;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            int mask = 0;
            int cur = i;
            lint fnd = a[i][j];
            vector<tuple<int, int, int>> sol;
            while ((mask & (1 << cur)) == 0) {
                mask |= (1 << cur);
                fnd = target - sum[cur] + fnd;
                if (pos.count(fnd) == 0) {
                    cur = -1;
                    break;
                }
                sol.emplace_back(pos[fnd], fnd, cur);
                cur = pos[fnd];
            }
            if (cur == i && fnd == a[i][j]) {
                ans[mask] = sol;
                masks.emplace_back(mask);
            }
        }
    }

    sort(begin(masks), end(masks));
    masks.resize(unique(begin(masks), end(masks)) - begin(masks));
    vector<bool> dp(1 << n);
    vector<int> prv(1 << n);
    dp[0] = true;

    for (auto mask : masks) {
        int no = ((1 << n) - 1) ^ mask;
        for (int nxt_mask = no; nxt_mask >= 0; nxt_mask = ((nxt_mask - 1) & no)) {
            if (dp[nxt_mask] && ((mask & nxt_mask) == 0)) {
                dp[nxt_mask | mask] = true;
                prv[nxt_mask | mask] = mask;
            }
            if (nxt_mask == 0) {
                break;
            }
        }
    }
    
    if (dp[(1 << n) - 1]) {
        cout << "Yes\n";
        vector<tuple<int, int, int>> res;
        int mask = (1 << n) - 1;
        while (mask != 0) {
            int bck = prv[mask];
            res.insert(res.end(), ans[bck].begin(), ans[bck].end());
            mask ^= bck;
        }
        sort(begin(res), end(res));
        for (auto i : res) {
            cout << get<1>(i) << " " << get<2>(i) + 1 << "\n";
        }
    } else {
        cout << "No\n";
    }
    return 0;
}