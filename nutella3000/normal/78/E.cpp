#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;
const int max_n = 1001;

int xdir[]{0, 0, -1, 1}, ydir[]{-1, 1, 0, 0};

vector<int> gr[max_n];
bool used[max_n];
int pa[max_n];



bool check(int x, int y, vector<string>& s) {
    return x >= 0 && y >= 0 && x < s.size() && y < s.size() && s[x][y] != 'Y' && s[x][y] != 'Z';
}

vector<vector<int>> bfs(int st_x, int st_y, vector<string> s) {
    vector<vector<int>> res(s.size(), vector<int>(s.size(), inf));
    res[st_x][st_y] = 0;
    deque<pii> b;
    b.emplace_back(st_x, st_y);

    while(b.size()) {
        pii v = b.front();
        b.pop_front();

        for(int i = 0;i < 4;i++) {
            int x = v.f + xdir[i];
            int y = v.s + ydir[i];
            if (!check(x, y, s) || res[x][y] != inf) continue;

            res[x][y] = res[v.f][v.s] + 1;
            b.emplace_back(x, y);
        }
    }

    return res;
}


void scan() {
    int n, t;
    cin >> n >> t;
    vector<string> s1(n), s2(n);
    for(int i = 0;i < n;i++)
        cin >> s1[i];

    for(int i = 0;i < n;i++)
        cin >> s2[i];

    int x_reac, y_reac;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if (s1[i][j] == 'Z') {
                x_reac = i;
                y_reac = j;
            }
        }
    }

    vector<vector<int>> reac = bfs(x_reac, y_reac, s1);


    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if (!check(i, j, s1)) continue;
            vector<vector<int>> a = bfs(i, j, s1);

            for(int x = 0;x < n;x++) {
                for(int y = 0;y < n;y++) {
                    if (!check(x, y, s1) || a[x][y] > t || a[x][y] > reac[x][y]) continue;

                    if (a[x][y] == reac[x][y]) {
                        bool good = false;
                        for(int id = 0;id < 4;id++) {
                            int xto = x + xdir[id];
                            int yto = y + ydir[id];
                            if (!check(xto, yto, s1) ||  a[xto][yto] >= reac[xto][yto]) continue;
                            good = true;
                        }
                        if (!good) continue;
                    }


                    for(int num1 = 1;num1 <= s1[i][j] - '0';num1++) {
                        for(int num2 = 1;num2 <= s2[x][y] - '0';num2++) {
                            gr[10 * (j + i * 10) + num1].emplace_back(10 * (y + 10 * x) + num2);
                        }
                    }
                }
            }
        }
    }
}

bool kuhn(int v) {
    if (used[v]) return false;
    used[v] = true;
    for(int to : gr[v]) {
        if (pa[to] == 0 || kuhn(pa[to])) {
            pa[to] = v;
            return true;
        }
    }
    return false;
}


void solve() {
    scan();


    int n = max_n;

    for(int i = 0;i < n;i++) {
        kuhn(i);
        for(int j = 0;j < n;j++)
            used[j] = false;
    }

    int res = 0;
    for(int i = 0;i < n;i++) res += pa[i] != 0;

    cout << res;
}



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}