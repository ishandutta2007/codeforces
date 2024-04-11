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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
 
void solve(){
    int n, k; cin >> n >> k;
    vector<int> a;
    for (int i = 1; i <= k+1; i++) {
        cout << "? ";
        for (int j = 1; j <= k+1; j++) if (j!=i) cout << j << ' ';
        cout << endl;
 
        int idx, val;
        cin >> idx >> val;
        a.push_back(val);
    }
    int mx=a[0];
    for (auto it : a) mx = max(mx, it);
    int ans=0;
    for (auto it : a) if (it == mx) ans++;
    cout<< "! " << ans <<endl;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}