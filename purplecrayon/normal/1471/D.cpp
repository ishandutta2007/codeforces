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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e6+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int prime[MAXA];

vector<int> get_pf(int a){
    vector<int> r;
    while (a > 1){
        r.push_back(prime[a]);
        a /= prime[a];
    }
    unordered_map<int, int> mp;
    for (auto& it : r) mp[it]++;
    r.clear();
    for (auto& it : mp) if (it.second&1) r.push_back(it.first);
    sort(r.begin(), r.end());
    return r;
}
void sieve(){
    memset(prime, -1, sizeof(prime));
    for (int i = 2; i < MAXA; i++) if (prime[i] == -1){
        prime[i] = i;
        for (int j = 2*i; j < MAXA; j += i) prime[j] = i;
    }
}
void solve(){
    //x*y must be a perfect square for them to be adjacent
    //adjacent to an even number of elements or i'm a perfect square -> i become a perfect square
    //otherwise -> i stay the same
    //if i'm a perfect square, only adjacent to other perfect squares
    //
    //if i'm adjacent to an odd number at the start, i'm never going to get fixed
    //otherwise, i'll change to a perfect square in one move, then stay like that
    int n; cin >> n;
    vector<int> a(n);
    for (auto& it : a) cin >> it;
    vector<vector<int>> pf(n);
    map<vector<int>, int> mp;
    for (int i = 0; i < n; i++){
        pf[i] = get_pf(a[i]);
        mp[pf[i]]++;
    }
    int n_sq=0, w_sq=0, oans=0;
    for (int i = 0; i < n; i++){
        int c=mp[pf[i]];
        oans = max(oans, c);
        if ((sz(pf[i]) == 0) || (c&1^1)) n_sq++;
        else w_sq = max(w_sq, c);
    }
    int nans = max(n_sq, w_sq);

    int q; cin >> q;
    while (q--){
        ll w; cin >> w;
        if (w == 0) cout << oans << '\n';
        else cout << nans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1; sieve();
    cin >> t_c;
    while (t_c--) solve();
}