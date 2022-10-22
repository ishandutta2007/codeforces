#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int arr[MAXN][MAXN];
string s[MAXN];
string ans[MAXN];

vector<char> ch = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

main() {
    for (int i = 0; i < 26; ++i) {
        ch.push_back('a' + i);
        ch.push_back('A' + i);
    }
    int t;
    cin >> t;
    while (t--) {
        int r, c, k;
        cin >> r >> c >> k;
        int cnt = 0;
        for (int i = 0; i < r; ++i) {
            cin >> s[i];
            ans[i] = "";
            for (int j = 0; j < c; ++j) {
                ans[i].push_back('.');
                arr[i][j] = 0;
                if (s[i][j] == 'R') {
                    arr[i][j] = 1;
                    cnt++;
                }
            }
        }
        int x = cnt / k;
        int y = cnt % k;
        vector<pair<int, int>> pth;
        for (int i = 0; i < r; ++i) {
            if (i % 2) {
                for (int j = 0; j < c; ++j) {
                    pth.push_back({i, j});
                }
            } else {
                for (int j = c - 1; j >= 0; --j) {
                    pth.push_back({i, j});
                }
            }
        }
        int cur = 0;
        for (int i = 0; i < k; ++i) {
            int nd = x;
            if (i < y) {
                nd++;
            }
            int cnt = 0;
            if (arr[pth[cur].first][pth[cur].second]) {
                cnt++;
            }
            while (cur < r * c && cnt <= nd) {
                ans[pth[cur].first][pth[cur].second] = ch[i];
                cur++;
                if (cur == r * c) {
                    break;
                }
                if (arr[pth[cur].first][pth[cur].second]) {
                    cnt++;
                }
            }
        }
        for (int i = 0; i < r; ++i) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}