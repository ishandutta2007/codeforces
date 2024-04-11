#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int solve();
// #define TESTCASE
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    #ifdef TESTCASE
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    #else
    solve();
    #endif
    return 0;
}

int solve() {
    int n;
    cin >> n;
    vector<int> ans(n);
    set<int> cand;
    vector<int> in(n), out(n);
    for (int i = 0; i < n; i++) {
        cand.emplace(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
        ans[i]--;
        if (ans[i] != -1) {
            in[ans[i]]++;
            out[i]++;
            cand.erase(ans[i]);
        }
    }
    deque<int> fs;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0 && out[i] == 0) {
            fs.emplace_front(i);
        }
    }

    for (auto i : fs) {
        if (ans[i] == -1) {
            for (auto& j : cand) {
                if (i != j) {
                    ans[i] = j;
                    break;
                }
            }
            cand.erase(ans[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            for (auto& j : cand) {
                if (i != j) {
                    ans[i] = j;
                    break;
                }
            }
            cand.erase(ans[i]);
        }
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";



}