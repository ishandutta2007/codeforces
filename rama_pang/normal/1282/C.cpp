#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define TESTCASE



int solve() {

    lint N, T, A, B;
    cin >> N >> T >> A >> B;
    vector<pair<lint, lint>> prob(N);
    map<lint, pair<lint, lint>> mp;
    lint cnt_ez = 0, cnt_hd = 0;

    for (int i = 0; i < N; i++) {
        cin >> prob[i].second;
        if (prob[i].second == 0) {
            cnt_ez++;
        } else {
            cnt_hd++;
        }
    }
    for (int i = 0; i < N; i++) {
        cin >> prob[i].first;
    }

    vector<pair<lint, pair<lint, lint>>> pref;

    for (int i = 0; i < N; i++) {
        if (prob[i].second == 0) mp[prob[i].first].first++;
        if (prob[i].second == 1) mp[prob[i].first].second++;
    }

    mp.insert({0, {0, 0}});
    mp.insert({T + 1, {0, 0}});

    for (auto i : mp) {
        pref.emplace_back(i);
    }

    for (int i = 1; i < (int)pref.size(); i++) {
        pref[i].second.first += pref[i - 1].second.first;
        pref[i].second.second += pref[i - 1].second.second;
    }

    vector<lint> ans(pref.size());

    for (int i = 0; i < (int)pref.size() - 1; i++) {
        lint t = pref[i + 1].first - 1;
        lint ez = pref[i].second.first;
        lint hd = pref[i].second.second;
        if (ez * A + hd * B <= t) {
            t -= ez * A + hd * B;
            lint ezl = cnt_ez - ez;
            lint hdl = cnt_hd - hd;
            lint can = t / A;
            if (can > ezl) {
                can = ezl;
            }
            t -= can * A;
            lint can2 = t / B;
            if (can2 > hdl) {
                can2 = hdl;
            }
            t -= can2 * B;
            assert(t >= 0);
            ans[i] = ez + hd + can + can2;
        } else {
            ans[i] = 0;
        }
    }

    lint res = 0;
    for (int i = 0; i < (int)pref.size() - 1; i++) {
        res = max(res, ans[i]);
    }
    cout << res << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    #ifdef TESTCASE
    cin >> T;
    #else
    T = 1;
    #endif
    while (T--) {
        solve();
    }
    return 0;
}