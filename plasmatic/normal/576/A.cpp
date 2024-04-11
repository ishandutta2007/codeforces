// ./a-vasya-and-petyas-game.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<int> ans;
    for (auto i = 1; i <= N; i++) {
        int pc = 0, c = i;
        for (auto j = 2; j * j <= c; j++) {
            if (c % j == 0) {
                while (c % j == 0) c /= j;
                pc++;
            }
        }
        if (c > 1) pc++;
        if (pc == 1) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';

    return 0;
}