#include <bits/stdc++.h>
// #define TESTCASE
using namespace std;
using lint = long long;
const lint INF = (1ll << 32);

lint N, x;
vector<pair<string, lint>> op;
vector<int> nxt;

lint dfs(int n) {
    if (n == N) return 0;
    
    string s = op[n].first;
    if (s == "add") {
        return min(1 + dfs(n + 1), INF);
    }

    if (s == "end") {
        return 0;
    }

    if (s == "for") {
        lint tmp = dfs(n + 1);
        tmp *= op[n].second;
        return min(tmp + dfs(nxt[n] + 1), INF);
    }


}

void solve() {
    cin >> N;
    x = 0;
    nxt.resize(N, -1);
    vector<int> fr;

    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        if (s == "for") {
            lint a; cin >> a;
            op.emplace_back(s, a);
            fr.emplace_back(i);
        } else {
            op.emplace_back(s, 0);
        }
        if (s == "end") {
            nxt[fr.back()] = i;
            fr.pop_back();
        }
    }

    x = dfs(0);
    if (x >= INF) {
        cout << "OVERFLOW!!!\n";
        return;
    }
    cout << x << "\n";

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    #ifdef TESTCASE
    cin >> tc;
    #endif

    while (tc--) solve();
}