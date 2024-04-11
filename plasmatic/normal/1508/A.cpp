// ./a-binary-literature.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;

const int MN = 2e5 + 1;
int N;
string s[3];

string build(int i, int j) {
    string res;
    vector<int> afterCnt[2];
    for (auto k = -1; k < N; ) {
        int n = k+1;
        while (n < N && s[i][n] == '1') n++;
        afterCnt[0].push_back(n-k-1);
        k = n;
    }

    for (auto k = -1; k < N; ) {
        int n = k+1;
        while (n < N && s[j][n] == '1') n++;
        afterCnt[1].push_back(n-k-1);
        k = n;
    }

    int sz = max(afterCnt[0].size(), afterCnt[1].size());
    for (auto k = 0; k < sz; k++) {
        int mx = max(k < (int)afterCnt[0].size() ? afterCnt[0][k] : 0, k < (int)afterCnt[1].size() ? afterCnt[1][k] : 0);
        for (auto l = 0; l < mx; l++) res += '1';
        if (k < sz-1) res += '0';
    }

    return res;
}

string sw(string s) {
    string res;
    for (auto c : s) {
        if (c == '0') res += '1';
        else res += '0';
    }

    return res;
}

void solve() {
    cin >> N >> s[0] >> s[1] >> s[2];
    N *= 2;

    int cnt[3][2]; memset(cnt, 0, sizeof cnt);
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < 3; j++) {
            cnt[j][s[j][i] - '0']++;
        }
    }

    for (auto i = 0; i < 3; i++) {
        for (auto j = i+1; j < 3; j++) {
            if (cnt[i][0] >= N/2 && cnt[j][0] >= N/2) {
                cout << build(i, j) << '\n';
                return;
            }
            if (cnt[i][1] >= N/2 && cnt[j][1] >= N/2) {
                s[i] = sw(s[i]);
                s[j] = sw(s[j]);
                string res = build(i, j);
                res = sw(res);
                cout << res << '\n';
                return;
            }
        }
    }

    assert(0);
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