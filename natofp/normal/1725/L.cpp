#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
#define mt make_tuple

using namespace std;


const int nax = 1e5 + 5;
ll a[nax];
ll pref[nax];
int n;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve(){
    cin >> n;
    vector<ll> good;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        good.pb(pref[i]);
    }
    sort(good.begin(), good.end());
    if(good[0] < 0 || good.back() != pref[n]){
        cout << -1 << "\n";
        return;
    }

    vector<ll> cur;
    for(int i=1;i<=n;i++) cur.pb(pref[i]);
    set<ll> uni;
    vector<ll> u;
    for(ll x : cur) uni.insert(x);
    for(ll x : uni) u.pb(x);
    for(int i=0;i<n;i++){
        cur[i] = (int)(lower_bound(u.begin(), u.end(), cur[i]) - u.begin());
    }
    FenwickTree tri(nax + 55);
    ll ans = 0;
    for(ll x :cur){
        ans += tri.sum(x + 1, nax);
        tri.add(x, 1);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}