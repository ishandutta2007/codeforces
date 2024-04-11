#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int solve();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    // cin >> T;
    T = 1;
    while (T--) solve();
    return 0;
}

int p[1000005];
int par(int n) {
    if (n == p[n]) return n;
    return p[n] = par(p[n]);
}

int solve() {

    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    vector<pair<int, pair<int, int>>> EV;
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        EV.push_back({A[i].first, A[i]});
        EV.push_back({A[i].second, A[i]});
        
    }

    sort(A.begin(), A.end());
    iota(p, p + N + N + 1, 0);
    sort(EV.begin(), EV.end());

    map<pair<int, int>, int> e;
    set<int> active;
    int cnte = 0;
    for (auto cur : EV) {
        pair<int, int> seg = cur.second;
        if (seg.first == cur.first) {
            for (auto i : active) {
                if (i > seg.second) {
                    break;
                }
                if (par(i) == par(seg.second) || cnte >= N) {
                    cout << "NO\n";
                    return 0;
                }
                p[par(i)] = par(seg.second);
                cnte++;
            }
            active.insert(seg.second);
        } else {
            active.erase(seg.second);
        }
    }

    if (cnte == N - 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


}