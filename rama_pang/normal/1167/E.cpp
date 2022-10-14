#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

int N, X;
vector<pair<int, int>> occ;
vector<int> maxx, A;

int32_t main() {
    cin >> N >> X;
    occ.assign(X + 4, make_pair(-1, -1));
    maxx.assign(N + 4, 0);
    int maks = 0;

    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        if (occ[a].fi == -1) occ[a].fi = i;
        occ[a].se = i;
        maxx[i] = max(maxx[i - 1], a);
    }
    int ans = 0;
    int bawah = 0, atas = X + 1;
    int cur_bawah = 0, cur_atas = N + 1;
    for (int i = X; i >= 1; i--) {
        if (occ[i].se == -1) {
            atas = i;
            continue;
        }
        if (cur_atas >= occ[i].se) {
            atas = i;
            cur_atas = occ[i].fi;
        } else {
            break;
        }
    }
    for (int i = 1; i <= X; i++) {
        // cout << i << " " << cur_bawah << "\n";
        ans += X - max(max(i, maxx[cur_bawah]), atas - 1) + 1;
        // cout << ans << "\n";
        if (occ[i].se != -1 && cur_bawah >  occ[i].fi) break;          
        if (occ[i].se != -1) cur_bawah = occ[i].se;               
    }
    cout << ans << "\n";
}