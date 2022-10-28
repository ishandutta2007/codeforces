#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

int n, deg[2*MAXN];
vector<int> a, b;
bool winning[2*MAXN], losing[2*MAXN], vis[2*MAXN];

vector<int> badj(int c, bool mv) {
    vector<int> v = (mv ? a : b);
    vector<int> ans;
    for (auto x : v) {
        int p = (c-x+n)%n;
        ans.push_back(p);
    }
    return ans;
}
void dfs(int c) {
    vis[c] = 1;
    for (auto _nxt : badj(c/2, c%2)) {
        int nxt = 2*_nxt+(c&1^1);
        if (!vis[nxt]) {
            if (losing[c])
                winning[nxt] = 1;
            else if (--deg[nxt] == 0)
                losing[nxt] = 1;
            else
                continue;
            dfs(nxt);
        }
    }
}
void solve(){
    cin >> n;
    {
        int k; cin >> k;
        a.resize(k);
        for (auto& c : a) cin >> c;
    }
    {
        int k; cin >> k;
        b.resize(k);
        for (auto& c : b) cin >> c;
    }

    for (int i = 0; i < 2*n; i++) {
        auto c = badj(i/2, i%2);
        for (auto x : c) deg[2*x + (i&1^1)]++;
    }

    losing[0] = 1, losing[1] = 1; vis[0] = 1; vis[1] = 1;
    dfs(0);
    dfs(1);

    for (int j : {0, 1}) {
    for (int i = 1; i < n; i++) {
        if (winning[2*i+j]) {
            cout << "Win ";
        } else if (losing[2*i+j]) {
            cout << "Lose ";
        } else cout << "Loop ";
    }
    cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}