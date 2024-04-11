#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void solve() {

    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    vector<pair<int, int>> ans;
    for (int i = 0; i < N; i++) {
        if (K > 1) {
            for (int j = i; j < N; j++) {
                if (s[j] == '(') {
                    ans.emplace_back(i, j);
                    reverse(s.begin() + i, s.begin() + j + 1);
                    break;
                }
            }
            i++;
            for (int j = i; j < N; j++) {
                if (s[j] == ')') {
                    ans.emplace_back(i, j);
                    reverse(s.begin() + i, s.begin() + j + 1);
                    break;
                }
            }
            K--;
        } else if (K == 1) {
            int ok = 0;
            while (1) {
                ok = 0;
                for (int j = i; j < N; j++) {
                    if (s[j] == '(') {
                        ok = 1;
                        ans.emplace_back(i, j);
                        reverse(s.begin() + i, s.begin() + j + 1);
                        break;
                    }
                }
                i++;
                if (ok == 0) {
                    break;
                }
            }
        } else {
            assert(0);
        }
    }

    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int TESTCASE;
    cin >> TESTCASE;
    // TESTCASE = 1;
    while (TESTCASE--) {
        solve();
    }
}