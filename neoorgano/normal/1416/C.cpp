#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5, MAXK = 1e7;
int arr[MAXN];
vector<int> mp[MAXK];
int cur = 0;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        mp[cur].push_back(i);
    }
    int x = 0;
    vector<int> val;
    val.push_back(cur);
    int64_t ans = 0;
    cur++;
    for (int i = 29; i >= 0; --i) {
        vector<int> val1;
        int64_t cnt0 = 0, cnt1 = 0;
        for (auto msk : val) {
            int ind0 = 0, ind1 = 0;
            int go0 = -1, go1 = -1;
            for (auto ind : mp[msk]) {
                if (arr[ind] & (1 << i)) {
                    cnt1 += ind0;
                    ind1++;
                    if (go1 == -1) {
                        go1 = cur;
                        val1.push_back(cur);
                        cur++;
                    }
                    mp[go1].push_back(ind);
                } else {
                    cnt0 += ind1;
                    ind0++;
                    if (go0 == -1) {
                        go0 = cur;
                        val1.push_back(cur);
                        cur++;
                    }
                    mp[go0].push_back(ind);
                }
            }
        }
        val = val1;
        ans += min(cnt0, cnt1);
        if (cnt0 > cnt1) {
            x |= (1 << i);
        }
    }
    cout << ans << " " << x;
    return 0;
}