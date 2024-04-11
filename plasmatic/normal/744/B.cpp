// ./b-hongcows-game.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

int N;

vector<int> ask(vector<int> v) {
    if (v.empty()) return vector<int>(N);

    cout << v.size() << '\n';
    for (auto x : v) cout << x << ' ';
    cout << '\n'; cout.flush();

    vector<int> res(N);
    for (auto &x : res) cin >> x;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<int> ans(N, INF);
    for (auto i = 0; i <= __lg(N); i++) {
        vector<int> lhs, rhs;
        for (auto j = 1; j <= N; j++) {
            if ((j >> i) & 1) rhs.push_back(j);
            else lhs.push_back(j);
        }

        auto lres = ask(lhs), rres = ask(rhs);
        for (auto j = 1; j <= N; j++) {
            if ((j >> i) & 1)
                ans[j-1] = min(ans[j-1], lres[j-1]);
            else
                ans[j-1] = min(ans[j-1], rres[j-1]);
        }
    }

    cout << "-1\n";
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
    cout.flush();

    return 0;
}