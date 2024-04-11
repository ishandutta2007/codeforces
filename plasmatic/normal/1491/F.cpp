// ./f-magnets.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

int N;
int ask(vector<int> l, vector<int> r) {
    cout << "? " << l.size() << ' ' << r.size() << "\n";
    for (auto x : l) cout << x << ' ';
    cout << '\n';
    for (auto x : r) cout << x << ' ';
    cout << '\n';
    cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    cin >> N;

    vector<int> ans;
    int f = -1;
    for (auto i = 1; i < N; i++) {
        vector<int> l;
        for (auto j = 0; j < i; j++)
            l.push_back(j+1);
        if (ask(l, {i+1})) {
            f = i;
            break;
        }
    }
    assert(f != -1);

    // binary search for first magnet
    int l = 0, r = f;
    while (l + 1 < r) {
        int mid = (l + r) / 2;

        vector<int> lhs;
        for (auto i = mid; i < f; i++)
            lhs.push_back(i+1);

        if (ask(lhs, {f+1})) l = mid;
        else r = mid;
    }
    // add everything <f and is not the first magnet
    for (auto i = 0; i < f; i++)
        if (i != l)
            ans.push_back(i+1);

    // brute force right
    for (auto i = f+1; i < N; i++) {
        if (!ask({f+1}, {i+1}))
            ans.push_back(i+1);
    }

    cout << "! " << ans.size() << ' ';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}