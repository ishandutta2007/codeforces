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

using namespace std;

const int nax = 5e5 + 5;
ll a[nax];
int n;
ll pref[nax];
map<ll, int> best;

vector<ll> u;
int g(ll x){
    return (int)(lower_bound(u.begin(), u.end(), x) - u.begin());
}

struct FenwickTreeMax {
    vector<int> bit;
    int n;
    const int INF = (int)-1e9;

    FenwickTreeMax(int n) {
        this->n = n;
        bit.assign(n, INF);
    }

    FenwickTreeMax(vector<int> a) : FenwickTreeMax(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int getmax(int r, bool flipped = false) {
        if(flipped) r = n - 1 - r;
        int ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val, bool flipped = false) {
        if(flipped) idx = n - 1 - idx;
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], val);
    }
};

int dp[nax];

void solve(){
    u.clear(); best.clear();
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) pref[i] = pref[i - 1] + a[i];
    for(int i=0;i<=n;i++){
        u.pb(pref[i]);
        u.pb(pref[i] - 1);
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    for(int i=0;i<=n;i++) pref[i] = g(pref[i]);
    ll inf = 1e9;
    for(int i=1;i<=n;i++) best[pref[i]] = -inf;
    best[pref[0]] = 0;
    FenwickTreeMax triMniejsze(n * 2 + 3);
    FenwickTreeMax triWieksze(n * 2 + 3);
    ll ofsetMniejsze = 0;
    ll ofsetWieksze = 0;
    dp[0] = 0;
    //for(auto x : u) cout << x << "\n";
    //cout << "C" << pref[0] << " " << pref[1] - 1 << "\n";
    //cout << "WA" << g(pref[0]) << " " << g(pref[1] - 1) << "\n";
    //return;
    triMniejsze.update(pref[0], -ofsetMniejsze);
    triWieksze.update(pref[0], -ofsetWieksze, true);
    for(int i=1;i<=n;i++){
        //cout<<i<<endl;
        ofsetMniejsze += 1;
        ofsetWieksze -= 1;
        int cur = pref[i];
        int c1 = triMniejsze.getmax(cur - 1) + ofsetMniejsze;
        int c2 = triWieksze.getmax(cur - 1, true) + ofsetWieksze;
        int c3 = best[cur];
        //cout << i << " " << c1 << " " << c2 << " " << c3 << "\n";
        dp[i] = max(c1, c2);
        dp[i] = max(dp[i], c3);
        int value = dp[i];
        best[cur] = max(best[cur], value);
        triMniejsze.update(cur, value - ofsetMniejsze);
        triWieksze.update(cur, value - ofsetWieksze, true);
    }

    cout << dp[n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}