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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
 
void solve(){
    int n; ll k; cin >> n >> k;
    vector<ll> a(n); for (auto& it : a) cin >> it;
    if (k == 0) { cout << n << '\n'; return; }
    ll mx=*max_element(a.begin(), a.end());
    if (mx == n-1){
        cout << n+k << '\n';
        return;
    }
    set<ll> s(a.begin(), a.end());
    int c=0; while (s.count(c)) c++;

    if (s.count((mx+c+1)/2)){
        cout << n << '\n';
    } else {
        cout << n+1 << '\n';
    }
    //max == n-1:
    //  will keep increasing
    //max == n
    //  the hole will never be filled -> it's always n
    //max >= n
    //  
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}