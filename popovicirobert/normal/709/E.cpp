#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 4e5;

vector <int> g[MAXN + 1];
int mx[MAXN + 1], sz[MAXN + 1], n;

void dfs(int nod, int par) {
    mx[nod] = sz[nod] = 1;
    for(auto it : g[nod]) {
        if(it != par) {
            dfs(it, nod);
            sz[nod] += sz[it];
            mx[nod] = max(mx[nod], mx[it]);
        }
    }
    if(sz[nod] <= n / 2) {
        mx[nod] = sz[nod];
    }
}

bool sol[MAXN + 1];

void solve(int nod, int par, int best) {
    bool ans = 1;
    for(auto it : g[nod]) {
        if(it != par) {
            if(sz[it] > n / 2) {
                if(mx[it] < sz[it] - n / 2) {
                    ans = 0;
                }
            }
        }
    }
    int deg = g[nod].size();
    vector <int> pref(deg + 1), suff(deg + 1);
    for(int i = 0; i < deg; i++) {
        if(g[nod][i] != par) {
            pref[i] = mx[g[nod][i]];
        }
        if(i > 0) {
            pref[i] = max(pref[i], pref[i - 1]);
        }
    }
    for(int i = deg - 1; i >= 0; i--) {
        if(g[nod][i] != par) {
            suff[i] = mx[g[nod][i]];
        }
        suff[i] = max(suff[i], suff[i + 1]);
    }
    if(n - sz[nod] > n / 2) {
        if(best < n - sz[nod] - n / 2) {
            ans = 0;
        }
    }
    //cerr << nod << " " << best << "\n";
    sol[nod] = ans;
    for(int i = 0; i < deg; i++) {
        if(g[nod][i] != par) {
            int cur = max(best, suff[i + 1]);
            if(i > 0) {
                cur = max(cur, pref[i - 1]);
            }
            if(n - sz[g[nod][i]] <= n / 2) {
                cur = n - sz[g[nod][i]];
            }
            solve(g[nod][i], nod, cur);
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    solve(1, 0, 0);
    for(i = 1; i <= n; i++) {
        cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}