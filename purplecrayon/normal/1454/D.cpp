#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    ll n; cin >> n;
    vector<pair<int, ll>> pf;
    for (ll i=2; i*i <= n; i++) if (n%i == 0){
        pf.emplace_back(0, i);
        while (n%i==0) pf.back().first++, n/=i;
    }
    if (n>1) pf.emplace_back(1, n);
    sort(pf.begin(), pf.end(), greater<pair<int, ll>>());
    int ln=pf[0].first;
    cout << ln << '\n';
    for (int i = 0; i < ln; i++){
        ll c=1;
        for (auto it : pf) if (ln-i-it.first <= 0) c *= it.second;
        cout << c << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}