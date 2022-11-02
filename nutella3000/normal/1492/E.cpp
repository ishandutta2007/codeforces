//  Clash Royale, [11.03.21 11:10]
#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin

#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define all(b) b.begin(), b.end()
#define fi first
#define se second
#define size(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double

const int inf = 5e9 + 7;
const int max_n = 3e5;

int n, m;
vector<vector<vector<int>>> blocks;
vector<int> cur;
vector<set<int>> bad;


void add(int id, int ind) {
    for (int i : blocks[id][ind])
        bad[i].erase(id);
    cur[id] = ind;
}

void rem(int id) {
    for (int i : blocks[id][cur[id]]) {
        bad[i].emplace(id);
    }
}

bool rec(int depth) {

    int cop = 0;
    for (int i = 0; i < n; i++) {
        if (size(bad[i]) > size(bad[cop])) cop = i;
    }

    if (size(bad[cop]) > 6) return false;
    if (size(bad[cop]) <= 2) return true;

    if (depth == 5) return false;

    vector<int> temp;
    for(int i : bad[cop])
        temp.emplace_back(i);
    for (int el : temp) {
        int ind = -1;
        for (int i1 = 0; i1 < size(blocks[el]); i1++) {
            for (auto i2 : blocks[el][i1]) {
                if (i2 == cop) ind = i1;
            }
        }
        if (ind == -1) while (n > 0) n++;

        int prev = cur[el];

        rem(el);
        add(el, ind);

        if (rec(depth + 1)) return true;

        rem(el);
        add(el, prev);
    }
    return false;
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    blocks.resize(m);
    cur.resize(m, -1);
    bad.resize(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];


    for (int i = 0; i < m; i++) {
        map<int, vector<int>> b;
        for (int j = 0; j < n; j++)
            b[a[j][i]].emplace_back(j);


        for (auto j : b) {
            if (cur[i] == -1 || size(blocks[i][cur[i]]) < size(j.se)) cur[i] = size(blocks[i]);
            blocks[i].emplace_back(j.se);
        }

        for (int ind = 0; ind < size(blocks[i]); ind++) {
            if (ind == cur[i]) continue;
            for (int j : blocks[i][ind])
                bad[j].emplace(i);
        }
    }

    if (!rec(1)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (int i = 0; i < m; i++) {
            cout << a[blocks[i][cur[i]][0]][i] << " ";
        }
        cout << endl;
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}