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
const int MAXN = 2e5+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<int> a(n), cnt(n); 
    for (auto& it : a) cin >> it, --it, cnt[it]++;
    
    vector<pair<int, int>> range(n, make_pair(n, -1));
    for (int i = 0; i < n; i++){
        range[a[i]].first = min(range[a[i]].first, i);
        range[a[i]].second = max(range[a[i]].second, i);
    }
    vector<int> cur(n);

    vector<int> dp(n+1, 0);
    for (int i = n-1; i >= 0; i--){
        cur[a[i]]++;    

        if (i < n-1) dp[i] = dp[i+1];
        if (i == range[a[i]].first) dp[i] = max(dp[i], cnt[a[i]]+dp[range[a[i]].second+1]);
        else dp[i] = max(dp[i], cur[a[i]]);
    }
    cout << n-dp[0] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}