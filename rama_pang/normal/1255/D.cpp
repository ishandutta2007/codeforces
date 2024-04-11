#include <bits/stdc++.h>
#define testcase int TESTCASE; cin >> TESTCASE; while (TESTCASE--)
#define db(x) cout << #x << " is " << x << "\n"
using namespace std;
using lint = long long;

vector<char> name;

void solve() {
    int R, C, K, rice = 0;
    cin >> R >> C >> K;
    vector<string> grid(R);
    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'R') rice++;
        }
    }

    int extra = rice % K;
    int all = rice / K;
    vector<int> num, yet;
    for (int i = 0; i < K; i++) {
        if (extra > 0) {
            extra--;
            num.emplace_back(all + 1);
        } else {
            num.emplace_back(all);
        }
    }
    vector<vector<char>> ans(R, vector<char>(C, ' '));


    auto in = [&] (int r, int c) {
        if (r < 0 || c < 0 || r >= R || c >= C) return false;
        if (ans[r][c] == ' ') return true;
        return false;
    };

    int ptr = 0, ptc = 0;
    int cnt = 0, cur = 0;
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    int dir = 0;
    while (cnt < R * C) {
        cnt++;
        if (num[cur] == 0 && grid[ptr][ptc] == 'R') cur++;
        ans[ptr][ptc] = name[cur];
        if (grid[ptr][ptc] == 'R') num[cur]--;


        if (!in(ptr + dr[dir], ptc + dc[dir])) {
            dir++;
            dir %= 4;
        }
        ptr += dr[dir];
        ptc += dc[dir];       
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 'a'; i <= 'z'; i++) {
        name.emplace_back(i);
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        name.emplace_back(i);
    }
    for (int i = '0'; i <= '9'; i++) {
        name.emplace_back(i);
    }


    int t; cin >> t;
    while (t--) solve();

}