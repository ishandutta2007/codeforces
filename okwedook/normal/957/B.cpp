#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main() {
    //ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &i : s) cin >> i;
    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            int cnt = 0;
            for (int j = 0; j < m; ++j) cnt += (s[i][j] == '#');
            if (cnt == 0) continue;
            for (int j = i + 1; j < n; ++j) {
                if (s[j] == s[i]) {
                    used[j] = true;
                    continue;
                }
                for (int k = 0; k < m; ++k) 
                    if (s[i][k] == s[j][k] && s[i][k] == '#') {
                        cout << "No";
                        return 0;
                    }
            }
        }
    }
    cout << "Yes";
    return 0;
}