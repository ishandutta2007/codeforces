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
const int MAXN = 5e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
 
int n, m, a[MAXN], dp[MAXN];

void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ld trash; cin >> trash;
    }
    for (int i = 0; i < n; i++){
        for (int j = a[i]; j >= 1; j--){
            dp[a[i]] = max(dp[a[i]], 1+dp[j]);
        }
    }
    cout << n-(*max_element(dp+1, dp+n+1)) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}