#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
 
const int inf = 1e17 + 7;

int n;
vector<vector<int>> dis, pref;
vector<int> l;

int f(int v, int h) {
    int l = -1;
    int r = dis[v].size();
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if (dis[v][mid] <= h) 
            l = mid;
        else 
            r = mid;
    }
    return l;
}

void solve() {
    int m;
    cin >> n >> m;
    l.resize(n + 1);
    dis.resize(n + 1);
    pref.resize(n + 1);

    for(int i = 2;i <= n;i++)
        cin >> l[i];

    for(int i = n;i >= 1;i--) {
        dis[i].emplace_back(0);
        for(int j = 2 * i;j <= 2 * i + 1;j++) {
            if (j > n)
                continue;
            for(int k : dis[j])
                dis[i].emplace_back(k + l[j]);
        }

        sort(dis[i].begin(), dis[i].end());
        for(int j : dis[i]) {
            int num = 0;
            if (pref[i].size())
                num = pref[i].back();

            pref[i].emplace_back(num + j);
        }
    }

    for(int i = 0;i < m;i++) {
        int st, h;
        cin >> st >> h;
        int num = f(st, h);
        int res = h * (num + 1) - pref[st][num];

        for(int v = st;v > 1;v = v / 2) {
            h -= l[v];

            if (h < 0)
                break;
            res += h;

            int sos = v ^ 1;

            if (sos <= n && h >= l[sos]) {
                num = f(sos, h - l[sos]);
                res += (h - l[sos]) * (num + 1) - pref[sos][num];
            }
        }

        cout << res << endl;
    }

}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}