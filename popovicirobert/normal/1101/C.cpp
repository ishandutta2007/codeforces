#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

struct DSU {
    vector <int> par;
    int n;
    DSU(int _n) {
        n = _n;
        par.resize(n + 1);
    }
    int root(int x) {
        if(par[x] == 0)
            return x;
        return par[x] = root(par[x]);
    }
    inline void join(int x, int y) {
        x = root(x), y = root(y);
        if(x != y) {
            par[x] = y;
        }
    }
};

struct Data {
    int l, r, pos;
    bool operator <(const Data &other) const {
        if(l == other.l)
            return r > other.r;
        return l < other.l;
    }
}arr[MAXN + 1];

int sol[MAXN + 1];
bool vis[MAXN + 1];


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t > 0) {
        t--;
        int n;
        cin >> n;
        for(i = 1; i <= n; i++) {
            int l, r;
            cin >> l >> r;
            arr[i] = {l, r, i};
        }
        sort(arr + 1, arr + n + 1);
        int mx = 0, id = 0;
        DSU dsu(n);
        for(i = 1; i <= n; i++) {
            vis[i] = 0;
            if(mx >= arr[i].l) {
                dsu.join(arr[i].pos, id);
            }
            if(mx < arr[i].r) {
                mx = arr[i].r;
                id = arr[i].pos;
            }
        }
        int cnt = 0;
        for(i = 1; i <= n; i++) {
            int x = dsu.root(i);
            if(vis[x] == 0) {
                cnt++;
                sol[x] = 2 - cnt % 2;
                vis[x] = 1;
            }
        }
        if(cnt == 1) {
            cout << -1 << "\n";
        }
        else {
            for(i = 1; i <= n; i++) {
                cout << sol[dsu.root(i)] << " ";
            }
            cout << "\n";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}