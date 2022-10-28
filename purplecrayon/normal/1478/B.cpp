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
const int MAXN = 1e5+10, MAXM = 1e2+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

bool good(ll x, int d){
    if (!x) return 0;
    else if (x%10 == d) return 1;
    else return good(x/10, d);
}
void solve(){
    int q, d; cin >> q >> d;
    
    vector<bool> g(10*d);
    for (int i = 0; i < sz(g); i++) g[i] = good(i, d);

    vector<bool> dp(10*d);
    dp[0]=1;
    for (int i = 1; i < sz(dp); i++) for (int j = 0; j < i && !dp[i]; j++) dp[i] = g[i-j]&&dp[j];

    while (q--){
        ll a; cin >> a;
        if (a < d) cout << no;
        else if (a >= 10*d) cout << yes;
        else {
            cout << (dp[a]?yes:no);
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}