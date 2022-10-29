#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 1000005;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string dir = "UDLR";
string rdir = "DURL";
int n, m;
string s[N];
string t[N];
int ans1 = 0, ans2 = 0;
int ncir = 0;
vector<ii> cir[N];
vector<int> check[N];

bool in(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int parse(char ch) {
    if (ch == 'U') return 0;
    if (ch == 'D') return 1;
    if (ch == 'L') return 2;
    if (ch == 'R') return 3;
}
void solve(int u) {
    int sz = cir[u].size();
    ans1 += sz;
    queue<pair<ii, int>> q;
    vector<bool> ok(sz, 0);
    set<ii> ss;
    q.push({cir[u][0], 0});
    if (s[cir[u][0].x][cir[u][0].y] == '0') ok[0] = 1;
    ss.insert(cir[u][0]);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        int xx = u.x.x;
        int yy = u.x.y;
        int val = u.y;
        for (int i = 0; i < 4; i++) {
            int x = xx + dx[i];
            int y = yy + dy[i];
            if (!in(x, y)) continue;
            if (ss.count({x, y})) continue;
            if (t[x][y] != rdir[i]) continue;
            int va = (val + 1) % sz;
            if (s[x][y] == '0') ok[va] = 1;
            q.push({{x, y}, va});
            ss.insert({x, y});
        }
    }
    for (int i = 0; i < sz; i++) if (ok[i]) ans2++;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        ans1 = ans2 = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            s[i] = " " + s[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> t[i];
            t[i] = " " + t[i];
        }
        int ti = 0;
        for (int i = 1; i <= n; i++) {
            check[i].resize(m + 1, 0);
            for (int &e : check[i]) e = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (check[i][j]) continue;
                ti++;
                int curx = i;
                int cury = j;
                while (1) {
                    check[curx][cury] = ti;
                    int foo = parse(t[curx][cury]);
                    curx += dx[foo];
                    cury += dy[foo];
                    
                    // cout << curx << ' ' << cury << endl;
                    if (check[curx][cury] == 0) continue;
                    if (check[curx][cury] != ti) break;
                    if (check[curx][cury] == ti) {
                        ncir++;
                        int nx = curx;
                        int ny = cury;
                        // cout << nx << ' ' << ny << endl;
                        do {
                            int baz = parse(t[nx][ny]);
                            nx += dx[baz];
                            ny += dy[baz];
                            cir[ncir].pb({nx, ny});
                        } while (nx != curx || ny != cury);
                        break;
                    }
                }
            }
        }
        // cout << ncir << endl;
        for (int i = 1; i <= ncir; i++) {
            solve(i);
            cir[i].clear();
        }
        cout << ans1 << ' ' << ans2 << '\n';
        ncir = 0;
    }
    return 0;
}