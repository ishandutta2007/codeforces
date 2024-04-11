#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e5+3, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};


void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (auto& r : a) for (auto& c : r) cin >> c;

    auto solve_1 = [&](vector<vector<int>>& mis) -> pair<int, int> { 
        //solve for the change_1 case, fix the second pos from the first row
        pair<int, int> mx_sz={0, -1};
        for (int i = 1; i < n; i++)
            mx_sz = max(mx_sz, {sz(mis[i]), i});

        if (mx_sz.first > 3) {
            return {-1, -1};
        } else if (mx_sz.first == 3) {
            for (int i : mis[mx_sz.second]) {
                bool bad=0;
                for (int k = 1; k < n && !bad; k++){
                    int ms = sz(mis[k]);
                    ms -= a[0][i] != a[k][i];
                    ms += a[mx_sz.second][i] != a[k][i];

                    bad |= ms > 2;
                }
                if (!bad) {
                    return {mx_sz.second, i};
                }
            }
            return {-1, -1};
        } else {
            return {0, 0}; //don't change anything
        }
        assert(false);
    };

    vector<vector<int>> mis(n);
    pair<int, int> mx_sz={0, -1};
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) if (a[0][j] != a[i][j]) mis[i].push_back(j);
        mx_sz = max(mx_sz, {sz(mis[i]), i});
    }
    if (mx_sz.first > 4){ 
        cout << "No\n";
        return;
    } else if (mx_sz.first == 4){
        for (int i : mis[mx_sz.second]) {
            for (int j : mis[mx_sz.second]) if (i > j) {
                bool bad=0;
                for (int k = 1; k < n && !bad; k++) {
                    int ms = sz(mis[k]);
                    ms -= a[0][i] != a[k][i];
                    ms -= a[0][j] != a[k][j];
                    ms += a[mx_sz.second][i] != a[k][i];
                    ms += a[mx_sz.second][j] != a[k][j];

                    bad |= ms > 2;
                }
                if (!bad){
                    cout << "Yes\n";
                    for (int k = 0; k < m; k++) {
                        int c=a[0][k];
                        if (k == i) c=a[mx_sz.second][k];
                        if (k == j) c=a[mx_sz.second][k];
                        cout << c << ' ';
                    }
                    cout << '\n';
                    return;
                }
            }
        }
        cout << "No\n";
        return;
    } else if (mx_sz.first == 3){
        for (int i : mis[mx_sz.second]) {

            vector<vector<int>> nmis(n);
            for (int k = 1; k < n; k++) {
                nmis[k] = mis[k];
                if (a[0][i] != a[k][i]) nmis[k].erase(find(nmis[k].begin(), nmis[k].end(), i));
                if (a[mx_sz.second][i] != a[k][i]) nmis[k].push_back(i);
            }
            int o=a[0][i];
            a[0][i]=a[mx_sz.second][i];
            auto ca = solve_1(nmis);

            if (ca.first == -1) {
                a[0][i]=o;
                continue;
            }
            cout << "Yes\n";
            for (int k = 0; k < m; k++){
                int c=a[0][k];
                if (k == ca.second) c=a[ca.first][k];
                if (k == i) c=a[mx_sz.second][k];
                cout << c << ' ';
            }
            cout << '\n';
            return;
        }
        cout << "No\n";
        return;
    } else { 
        cout << "Yes\n";
        for (int i = 0; i < m; i++) cout << a[0][i] << ' ';
        cout << '\n';
        return;
    }
    assert(false);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1; 
    //cin >> t_c;
    while (t_c--) solve();
}