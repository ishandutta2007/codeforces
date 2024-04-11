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
const int MAXN = 3e3+10, MAXM = 5e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 110, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<ar<ll, 2>> a(n);
    for (auto& it : a) cin >> it[0] >> it[1];
    vector<ar<ll, 3>> av(n);
    for (int i = 0; i < n; i++) av[i] = {a[i][0], a[i][1], i};
    
    vector<int> ans; ans.reserve(n);
    ans.push_back(n-1); 
    auto c = av.back(); av.pop_back();

    auto sq = [&](ll x){
        return x*x;
    };
    auto dist = [&](auto a, auto b){
        return sq(a[0]-b[0])+sq(a[1]-b[1]);
    };
    while (sz(av)){
        pair<ll, int> d{-1, -1};
        for (int i = 0; i < sz(av); i++) d=max(d, {dist(c, av[i]), i});

        c = av[d.second], ans.push_back(c[2]);
        av.erase(av.begin()+d.second);
    }
    for (auto& it : ans) cout << (it+1) << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}