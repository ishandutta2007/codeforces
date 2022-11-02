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
const int max_n = 1e5 + 5;
int n;
vector<int> gr[max_n];
int used[max_n][2];

vector<int> path;

bool draw = false;

bool dfs(int v, int st) {
    if (used[v][st]) {
        if (used[v][st] == 1)
            draw = true;
        //cout << v << " " << st << endl;
        return false;
    }

    path.emplace_back(v);
    used[v][st] = 1;
    for(int i : gr[v]) {
        if (dfs(i, 1 - st)) return true;
    }
    if (gr[v].empty() && st == 1) return true;
    path.pop_back();
    used[v][st] = 2;
    return false;
}

void solve() {
    int m;
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        int c;
        cin >> c;
        for(int j = 0;j < c;j++) {
            int to;
            cin >> to;
            to--;
            gr[i].emplace_back(to);
        }
    }

    int s;
    cin >> s;
    s--;
    dfs(s, 0);

    if (path.size()) {
        cout << "Win" << endl;
        for(int i : path)
            cout << i + 1 << " ";
    }else if (draw) cout << "Draw";
    else cout << "Lose";
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}