// ./b-invariance-of-tree.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e5 + 1;
int N,
    P[MN];
bool vis[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (auto i = 1; i <= N; i++)
        cin >> P[i];

    vector<vector<int>> cycs;
    for (auto i = 1; i <= N; i++) {
        if (!vis[i]) {
            vector<int> cyc;
            for (auto c = i; !vis[c]; c = P[c]) {
                cyc.push_back(c);
                vis[c] = true;
            }
            cycs.push_back(cyc);
        }
    }
    sort(cycs.begin(), cycs.end(), [&] (const auto &a, const auto &b) { return a.size() < b.size(); });
    if (cycs[0].size() == (size_t)1) {
        cout << "YES\n";
        int rt = cycs[0][0];
        for (auto i = 1; i <= N; i++)
            if (i != rt)
                cout << rt << ' ' << i << '\n';
        return 0;
    }
    else if (cycs[0].size() != (size_t)2)
        return cout << "NO\n", 0;
    else {
        for (auto &cyc : cycs)
            if (cyc.size() % 2)
                return cout << "NO\n", 0;

        int sz = cycs.size();
        cout << "YES\n" << cycs[0][0] << ' ' << cycs[0][1] << '\n';
        for (auto i = 1; i < sz; i++) {
            auto &v = cycs[i];
            int vsz = v.size();
            for (auto j = 0; j < vsz; j += 2) {
                cout << cycs[0][0] << ' ' << v[j] << '\n';
                cout << cycs[0][1] << ' ' << v[j+1] << '\n';
            }
        }
    }

    return 0;
}