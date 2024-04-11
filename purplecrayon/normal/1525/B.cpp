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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 1e2+10,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e9+10;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (auto& it : a) cin >> it;

    if (is_sorted(a.begin(), a.end())) cout << 0 << '\n';
    else if (a[0] == 1 || a[n-1] == n) cout << 1 << '\n';
    else if (a[0] != n || a[n-1] != 1) cout << 2 << '\n';
    else cout << 3 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}