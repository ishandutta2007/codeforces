#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
typedef long double ld;

const int inf = 1e15;
const int max_n = 2e5 + 4;

vector<int> gr[max_n];
int deep[max_n];
pii din[max_n], dout[max_n];

void dfs1(int v, int pr = -1) {
    if (pr != -1) deep[v] = deep[pr] + 1;
    din[v] = {0, v};

    for(int i : gr[v]) {
        if (i == pr) continue;
        dfs1(i, v);
        pii temp(din[i].fi + 1, din[i].se);
        din[v] = max(din[v], temp);
    }
}

void dfs2(int v, int pr = -1) {
    if (pr == -1) dout[v] = {0, v};
    //cout << v << endl;

    vector<int> temp;
    for(int i : gr[v]) {
        if (i != pr)
            temp.emplace_back(i);
    }

    sort(all(temp), [](int v1, int v2) {return din[v1] > din[v2];});

    pii m(-inf, inf);
    if (sz(temp) > 1) m = mp(din[temp[1]].fi + 1, din[temp[1]].se);

    for(int id = 0;id < sz(temp);id++) {
        if (id == 1) {
            m = mp(din[temp[0]].fi + 1, din[temp[0]].se);
        }
        int to = temp[id];
        
        dout[to] = max(m, dout[v]);
        dout[to].fi++;
    }

    for(int i : temp)
        dfs2(i, v);
}

int res = 0;
int a, b, c;

void dfs3(int v, int pr = -1) {
    vector<pii> vert;

    for(int i : gr[v]) {
        if (i != pr) {
            dfs3(i, v);
            pii temp(din[i].fi + 1, din[i].se);
            vert.emplace_back(temp);
        }
    }

    vert.emplace_back(dout[v]);
    if (pr != -1) vert.emplace_back(0, v);
    sort(all(vert), [](pii v1, pii v2) {return v1 > v2;});

    if (sz(vert) >= 3) {
        int new_res = vert[0].fi + vert[1].fi + vert[2].fi;
        if (new_res > res) {
            res = new_res;
            a = vert[0].se;
            b = vert[1].se;
            c = vert[2].se;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i = 0;i < n - 1;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace_back(v2);
        gr[v2].emplace_back(v1);
    }

    //cout << "bef" << endl;
    dfs1(0);
    //cout << "111" << endl;
    dfs2(0);
    //cout << "222" << endl;

    //for(int i = 0;i < n;i++)
    //    cout << i + 1 << " " << din[i].fi << " " << din[i].se + 1 << " " << dout[i].fi << " " << dout[i].se + 1 << endl;
    dfs3(0);

    cout << res << endl << a + 1 << " " << b + 1 << " " << c + 1 << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}