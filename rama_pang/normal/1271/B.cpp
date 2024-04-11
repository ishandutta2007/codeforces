#include <bits/stdc++.h>
// #define TESTCASE
using namespace std;
using lint = long long;
int solve();
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




int solve() {

    int N;
    cin >> N;
    string s;
    cin >> s;
    int b = 0, w = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') b++;
        else w++;
    }
    if (b == 0 || w == 0) {
        cout << 0 << "\n";
        return 0;
    }
    if (b % 2 == 1 && w % 2 == 1) {
        cout << -1 << "\n";
        return 0;
    }
    char key = 'B';
    vector<int> op;
    if (b % 2 == 0) key = 'W';
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != key) {
            op.emplace_back(i);
            s[i] = key;
            if (s[i + 1] == 'B') {
                s[i + 1] = 'W';
            } else {
                s[i + 1] = 'B';
            }
        }
    }
    cout << op.size() << "\n";
    for (auto i : op) cout << i + 1 << " ";

}