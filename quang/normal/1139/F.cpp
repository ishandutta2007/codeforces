#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int p[N], s[N], b[N], inc[N], pref[N];
vector<pair<int, int>> events;

struct BIT {
    int t[N << 1];
    void add(int x, int v) {
        x++;
        while (x < N * 2) {
            t[x] += v;
            x += (x & -x);
        }
    }
    int get(int x) {
        x++;
        int res = 0;
        while (x) {
            res += t[x];
            x -= x & -x;
        }
        return res;
    }
} sum, diff;

int res[N];
vector<int> valSum, valDiff;

int getPos(vector<int> &u, int val) {
    return lower_bound(u.begin(), u.end(), val) - u.begin();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) cin >> inc[i];
    for (int i = 1; i <= m; i++) cin >> pref[i];

    for (int i = 1; i <= n; i++) {  
        valSum.push_back(p[i] + b[i]);
        valDiff.push_back(1 + b[i] - p[i]);
        events.push_back({p[i], i});
        events.push_back({s[i] + 1, -i});
    }
    for (int i = 1; i <= m; i++) {
        valSum.push_back(inc[i] + pref[i]);
        valDiff.push_back(pref[i] - inc[i]);
        events.push_back({inc[i], i + n});
    }
    sort(events.begin(), events.end());
    sort(valSum.begin(), valSum.end());
    sort(valDiff.begin(), valDiff.end());
    valSum.resize(unique(valSum.begin(), valSum.end()) - valSum.begin());
    valDiff.resize(unique(valDiff.begin(), valDiff.end()) - valDiff.begin());
    for (int i = 0; i < events.size(); i++) {
        if (abs(events[i].second) > n) {
            int id = events[i].second - n;
            int now = sum.get(getPos(valSum, inc[id] + pref[id])) + diff.get(getPos(valDiff, pref[id] - inc[id]));
            res[id] += now;
            // cout << i << " get " << id << ' ' << inc[id] + pref[id] << ' ' << pref[id] - inc[id] << endl;
            // cout << sum.get(getPos(valSum, inc[id] + pref[id])) << ' ' << diff.get(getPos(valDiff, pref[id] - inc[id])) << endl;
        }
        if (abs(events[i].second) <= n) {
            int id = abs(events[i].second);
            sum.add(getPos(valSum, p[id] + b[id]), events[i].second > 0 ? 1 : -1);
            diff.add(getPos(valDiff, 1 + b[id] - p[id]), events[i].second < 0 ? 1 : -1);
            // cout << i << " update " << id << ' ' << b[id] + p[id] << ' ' << 1 + b[id] - p[id] << endl;
        }
    }
    for (int i = 1; i <= m; i++) cout << res[i] << ' ';
        cout << endl;
    return 0;
}