#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int solve() {
    int x, y;
    cin >> x >> y;
    vector<string> s(x);
    for (int i = 0; i < x; i++) {
        s[i] = "";
        for (int j = 0; j < y; j++) {
            s[i].push_back('0');
        }
    }
    s[0][0] = s[x - 1][0] = s[0][y - 1] = s[x - 1][y - 1] = '1';
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (i == 0 || i == x - 1 || j == 0 || j == y - 1) {
                bool ok = true;
                for (int dir = 0; dir < 4; dir++) {
                    int xx = i + dx[dir], yy = j + dy[dir];
                    if (xx >= 0 && xx < x && yy >= 0 &&  yy < y && s[xx][yy] == '1') {
                        ok = false;
                    }
                }
                if (ok) {
                    s[i][j] = '1';
                }
            }
        }
    }
    for (int i = 0; i < x; i++) {
        cout << s[i] << '\n';
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1e9;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}