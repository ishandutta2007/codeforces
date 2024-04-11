#include <bits/stdc++.h>
#define fi first
#define se second
#define db(x) cout << #x << " is " << x << "\n"
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int N, Q;
deque<pair<pair<int, int>, int>> interval;
pair<int, int> inter[200005];
int frek[200005];
int main() {
    IOS;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        inter[a].fi = (inter[a].fi == 0)? i : inter[a].fi;
        inter[a].se = i;
        frek[a]++;
    }
    for (int i = 1; i <= 200000; i++) {
        if (inter[i].fi == 0) continue;
        interval.push_back({inter[i], frek[i]});
    }
    sort(interval.begin(), interval.end());
    int cur = 1, last = 1, maks = 0;
    int ans = 0;
    for (int i = 0; i <= interval.size(); i++) {
        if (i == interval.size() || cur < interval[i].fi.fi) {
            ans += (cur - last + 1) - maks;
            maks = interval[i].se;
            last = interval[i].fi.fi;
            if (i < interval.size()) cur = interval[i].fi.se;
        } else {
            maks = max(maks, interval[i].se);
            cur = max(cur, interval[i].fi.se);
        }
        // cout << last << " " << cur << " " << maks << "\n";
    }
    cout << ans << "\n";
}