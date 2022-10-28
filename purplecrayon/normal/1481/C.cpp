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
const int MAXN = 5e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n); for (auto& it : a) cin >> it, --it;
    vector<int> b(n); for (auto& it : b) cin >> it, --it;
    vector<int> c(m); for (auto& it : c) cin >> it, --it;

    bool bad=1;
    vector<int> ans(m);
    for (int i = 0; i < n; i++){
        if (a[i] != b[i] && b[i] == c[m-1]){
            a[i] = b[i];

            bad=0;
            ans[m-1] = i;
            break;
        }
    }
    if (bad){
        for (int i = 0; i < n; i++){
            if (b[i] == c[m-1]){
                bad=0;
                ans[m-1] = i;
                break;
            }
        }
    }
    if (bad){ cout << no; return; }

    vector<int> ca(n), cb(n);
    for (int i = 0; i < n; i++) if (a[i] != b[i]) ca[b[i]]++;
    for (int i = 0; i < m-1; i++) cb[c[i]]++;

    for (int i = 0; i < n; i++) if (cb[i] < ca[i]){ cout << no; return; }

    cout << yes;

    vector<vector<int>> al(n);
    for (int i = 0; i < n; i++) if (a[i] != b[i]) al[b[i]].push_back(i);
    for (int i = 0; i < m-1; i++){
        if (sz(al[c[i]])){
            ans[i] = al[c[i]].back(), al[c[i]].pop_back();
        } else ans[i] = ans[m-1];
    }
    for (auto& it : ans) cout << (it+1) << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}