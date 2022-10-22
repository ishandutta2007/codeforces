#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5;
int s[MAXN];
pair<int, int> quest[MAXN];
int ansarr[MAXN];

main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    sort(s, s + n);
    for (int i = 0; i < n; ++i) {
        s[i] = s[i + 1] - s[i];
    }
    sort(s, s + n - 1);
    n--;
    s[n] = 2e18;
    int now = 0;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        r -= l;
        r++;
        quest[i] = {r, i};
    }
    sort(quest, quest + q);
    int ans = 0;
    int cnt = n + 1;
    for (int i = 0; i < q; ++i) {
        int k = quest[i].first;
        // cout << k << endl;
        while (now < n && s[now] <= k) {
            // cout << now << endl;
            ans += s[now];
            now++;
            cnt--;
        }
        // cout << ans << " " << cnt << endl;
        ansarr[quest[i].second] = ans + cnt * k;
    }
    for (int i = 0; i < q; ++i) {
        cout << ansarr[i] << " ";
    }
    return 0;
}