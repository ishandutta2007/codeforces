// ./c-phoenix-and-towers.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

using pii = pair<int, int>;

const int MN = 1e5 + 1;
int N, M, X,
    H[MN];

void solve() {
    cin >> N >> M >> X;
    for (auto i = 0; i < N; i++)
        cin >> H[i];

    vector<int> ass(N);
    priority_queue<pii, vector<pii>, greater<pii>> hs;
    for (auto i = 0; i < M; i++)
        hs.emplace(0, i);
    for (auto i = 0; i < N; i++) {
        auto [curh, idx] = hs.top(); hs.pop();
        ass[i] = idx;
        hs.emplace(curh+H[i], idx);
    }
    
    vector<int> fhs;
    while (!hs.empty()) {
        int a = hs.top().first; hs.pop();
        fhs.push_back(a);
    }
    if (fhs[M-1] - fhs[0] > X) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (auto i = 0; i < N; i++) cout << ass[i]+1 << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}