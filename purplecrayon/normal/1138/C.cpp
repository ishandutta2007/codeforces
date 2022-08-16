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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void smax(int& a, int b){ if (a < b) a = b; }
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> g[i][j];
    vector<vector<int>> lo(n, vector<int>(m)), hi(n, vector<int>(m));
    map<int, int> mp;
    for (int i = 0; i < n; i++){
        mp.clear();
        for (int j = 0; j < m; j++) mp[g[i][j]]++;
        int cc=0; for (auto& it : mp) it.second=cc++;

        for (int j = 0; j < m; j++){ 
            int lv=mp[g[i][j]], hv=sz(mp)-lv-1;
            smax(lo[i][j], lv), smax(hi[i][j], hv);
        }
    }
    for (int j = 0; j < m; j++){
        mp.clear();
        for (int i = 0; i < n; i++) mp[g[i][j]]++;
        int cc=0; for (auto& it : mp) it.second=cc++;

        for (int i = 0; i < n; i++){ 
            int lv=mp[g[i][j]], hv=sz(mp)-lv-1;
            smax(lo[i][j], lv), smax(hi[i][j], hv);
        }
    }
    //for (int i = 0; i < n; i++){ for (int j = 0; j < m; j++) cout << lo[i][j] << ' '; cout << '\n'; }
    //for (int i = 0; i < n; i++){ for (int j = 0; j < m; j++) cout << hi[i][j] << ' '; cout << '\n'; }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << lo[i][j]+1+hi[i][j] << ' ';
        cout << '\n';
    }

}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve(); 
}