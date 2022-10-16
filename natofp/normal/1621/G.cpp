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

const int mod = 1e9 + 7;

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
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret % mod;
    }

    int sum(int l, int r) {
        int w = sum(r) - sum(l - 1);
        if(w < 0) w += mod;
        return w;
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1)){
            bit[idx] += delta;
            if(bit[idx] >= mod) bit[idx] -= mod;
        }
    }
};

const int nax = 2e5 + 5;
int n;
int a[nax];

int prefix[nax];
int sufix[nax];

vector<int> whoDominated[nax];
int pos[nax];

void solve(){
    cin >> n;
    for(int i=0;i<=n;i++) whoDominated[i].clear();
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<pii> s;
    for(int i=1;i<=n;i++) s.pb(mp(a[i], -i));
    sort(s.begin(), s.end());
    for(int i=0;i<n;i++) a[-s[i].nd] = i + 1;
    for(int i=1;i<=n;i++) pos[a[i]] = i;

    FenwickTree tri1(n + 2);
    for(int i=1;i<=n;i++){
        int sum = tri1.sum(0, a[i]);
        sum += 1;
        sum %= mod;
        prefix[i] = sum;
        tri1.add(a[i], sum);
    }

    FenwickTree tri2(n + 2);
    for(int i=n;i>=1;i--){
        int sum = tri2.sum(a[i], n);
        sum += 1;
        sum %= mod;
        sufix[i] = sum;
        tri2.add(a[i], sum);
    }
    int filled = 0;
    for(int i=n;i>=1;i--){
        int v = a[i];
        for(int j=filled+1;j<=v-1;j++){
            if(pos[j] < i){
                whoDominated[i].pb(pos[j]);
            }
        }
        filled = max(filled, v - 1);
    }

    ll ans = 0;

    FenwickTree tri3(n + 2);
    set<int> good;

    for(int i=1;i<=n;i++){
        if(whoDominated[i].size()){
            vector<int> p = whoDominated[i];
            sort(p.begin(), p.end());
            reverse(p.begin(), p.end());
            vector<pii> upd;
            tri3.add(a[i], 1);
            upd.pb(mp(a[i], 1));
            for(int cur : p){
                good.insert(cur);
                int val = a[cur];
                int cnt = tri3.sum(val, n);
                tri3.add(val, cnt);
                upd.pb(mp(val, cnt));
                ll pr = prefix[cur];
                ll sf = sufix[i];
                ll gone = (pr * sf) % mod;
                gone *= cnt;
                gone %= mod;
                ans -= gone;
                if(ans < 0) ans += mod;
            }
            for(pii cur : upd){
                tri3.add(cur.st, (mod - cur.nd) % mod);
            }
        }
    }
    for(int x : good){
        ll cur = (ll)prefix[x] * sufix[x];
        cur %= mod;
        ans += cur;
        ans %= mod;
    }

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}