#include <bits/stdc++.h>
 
using namespace std;
 
#define aidar asadulin
 
//#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double

const int inf = 1e15;
const int max_n = 1e5 + 2;

struct dsu {
    map<int, int> p;

    dsu() {}

    int get(int v) {
        int s = v;
        while(p.count(v) && p[v] != v) v = p[v];

        while(s != v) {
            int t = p[s];
            p[s] = v;
            s = t;
        } 
        return v;
    }

    void merge(int v1, int v2) {
        p[get(v1)] = get(v2);
    }
};

map<int, vector<int>> groups[max_n];
vector<pii> gr[max_n];
vector<int> big_res[max_n];
dsu comps[max_n];

const int sqrt_n = 400;
int n, m;

void scan() {
    cin >> n >> m;

    set<int> temp[max_n];
    for(int i = 0;i < m;i++) {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;
        v1--; v2--; c--;

        temp[v1].emplace(c);
        temp[v2].emplace(c);

        comps[c].merge(v1, v2);
    }


    for(int i = 0;i < n;i++) {
        for(int j : temp[i]) {
            int coc = comps[j].get(i);
            gr[i].emplace_back(j, coc);
            groups[j][coc].emplace_back(i);
        }
    }


    for(int i = 0;i < n;i++) {
        if (sz(gr[i]) > sqrt_n) {
            big_res[i].resize(n);
            for(auto j : gr[i]) {
                for(int to : groups[j.fi][j.se]) {
                    big_res[i][to]++;
                }
            }
        }
    }
}

int get_min(int v1, int v2) {
    int res = 0;
    int id1 = 0, id2 = 0;
    while(id1 < sz(gr[v1]) && id2 < sz(gr[v2])) {

        if (gr[v1][id1].fi < gr[v2][id2].fi) id1++;
        else if (gr[v1][id1].fi > gr[v2][id2].fi) id2++;
        else {
            res += gr[v1][id1].se == gr[v2][id2].se;
            id1++; id2++;
        }
    }

    return res;
}

int get(int v1, int v2) {
    if (sz(gr[v1]) > sqrt_n)
        return big_res[v1][v2];

    if (sz(gr[v2]) > sqrt_n)
        return big_res[v2][v1];

    return get_min(v1, v2);
}

void solve() {
    scan();

    int q;
    cin >> q;
    for(int i = 0;i < q;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        cout << get(v1 - 1, v2 - 1) << endl;
    }
}

 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}