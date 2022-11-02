#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const int inf = 1e16;
const int max_n = 5e3 + 2;

int n, money;
int dp[max_n][max_n][2];
vector<pii> gr[max_n];
int sz[max_n];
int c[max_n];

void dfs(int v, int disk) {
    sz[v] = 1;
    vector<int> a[2];

    for(auto i : gr[v]) {
        dfs(i.fi, i.se);
        sz[v] += sz[i.fi];
    }

    sort(gr[v].begin(), gr[v].end(), [](pii v1, pii v2) {return sz[v1.fi] > sz[v2.fi];});

    a[0].resize(sz[v] + 1, inf);
    a[1].resize(sz[v] + 1, inf);
    a[1][1] = c[v] - disk;
    a[0][0] = 0;
    a[0][1] = c[v];

    for(int id = 0;id < 2;id++) {
        for(auto temp : gr[v]) {
            int to = temp.fi;
            int cost = temp.se;

            for(int i = sz[v];i >= 0;i--) {
                if (a[id][i] == inf) continue;

                for(int d = 0;d <= id;d++) {
                    for(int j = 0;j <= sz[to];j++) {
                        if (dp[to][j][d] == inf) continue;

                        int num = a[id][i] + dp[to][j][d];

                        a[id][i + j] = min(a[id][i + j], num);
                        /*if (v == 1 && id == 1 && i + j == 3) {
                            cout << j << " " << d << " " << to << " " << dp[to][j][d] << endl; 
                            cout << dp[4][]
                        }*/
                    }
                }
            }
        }
    }

    for(int i = 0;i < 2;i++) {
        for(int j = 0;j <= sz[v];j++) 
            dp[v][j][i] = a[i][j];
    }
}

void scan() {
    cin >> n >> money;
    for(int i = 0;i < n;i++) {
        int v, d;
        cin >> c[i] >> d;
        if (i == 0) c[i] -= d;
        else {
            cin >> v;
            gr[v - 1].emplace_back(i, d);
        }
    }
}

void solve() {
    scan();

    dfs(0, 0);

    /*for(int i = 0;i < n;i++) {
        cout << i + 1 << ": " << endl;
        for(int j = 0;j < 2;j++) {
            cout << j << "-" << endl;
            for(int q = 0;q <= n;q++)
                cout << dp[i][q][j] << " ";
            cout << endl;
        }
        cout << endl;
    }*/

    int res = 0;
    for(int i = 0;i <= n;i++)
        for(int j = 0;j < 2;j++)
            if (dp[0][i][j] <= money) res = i;

    cout << res;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}