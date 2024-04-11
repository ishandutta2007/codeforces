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

const int nax = 2e5 + 5;
const int mod = 998244353;
int a[nax];
int n, x;
ll pe[nax];

ll pp(ll a, ll b){
    if(b == 0) return 1;
    ll ans = pp(a,b/2);
    ans*=ans;
    ans%=mod;
    if(b&1){
        ans*=a;
        ans%=mod;
    }
    return ans;
}

ll get(int sz){
    ll res = pe[sz] - 1;
    if(res < 0) res += mod;
    return res;
}

ll go(vector<int> zero, vector<int> one, int b){
    if(zero.empty() || one.empty()) return 0LL;
    if(b < 0){
        ll res = get(zero.size());
        res *= get(one.size());
        res %= mod;
        return res;
    }
    vector<int> s00, s01, s10, s11;
    for(int x : zero){
        if(x & (1 << b)) s01.pb(x);
        else s00.pb(x);
    }
    for(int x : one){
        if(x & (1 << b)) s11.pb(x);
        else s10.pb(x);
    }
    if(x & (1 << b)){
        ll r1 = go(s00, s11, b - 1) + get(s00.size()) + get(s11.size()) + 1;
        ll r2 = go(s01, s10, b - 1) + get(s01.size()) + get(s10.size()) + 1;
        r1 %= mod;
        r2 %= mod;
        ll res = (r1 * r2) % mod;
        ll tooMuch = 1;
        tooMuch += get(zero.size()) + get(one.size());
        tooMuch %= mod;
        res -= tooMuch;
        if(res < 0) res += mod;
        return res;
    }
    else{
        ll res = go(s00, s10, b - 1) + go(s01, s11, b - 1);
        res %= mod;
        return res;
    }
}

void solve(){
    cin >> n >> x;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(x == 0){
        sort(a + 1, a + n + 1);
        ll ans = 0;
        ll cur = 1;
        for(int i=2;i<=n;i++){
            if(a[i] == a[i - 1]) cur += 1;
            else{
                ans += get(cur);
                ans %= mod;
                cur = 1;
            }
        }
        ans += get(cur);
        ans %= mod;
        cout << ans << "\n";
        return;
    }
    int b = 0;
    while((1 << b) * 2 <= x) b += 1;
    map<int, vector<int> > s;
    int msk = (1 << b) * 2 - 1;
    msk = (1 << 30) - 1 - msk;
    for(int i=1;i<=n;i++){
        int v = a[i];
        s[v & msk].pb(v);
    }
    ll ans = 0;
    for(auto cur : s){
        auto wek = cur.nd;
        vector<int> one;
        vector<int> zero;
        for(int cur : wek){
            if(cur & (1 << b)) one.pb(cur);
            else zero.pb(cur);
        }
        ans += get(one.size());
        ans += get(zero.size());
        ans %= mod;
        ans += go(zero, one, b - 1);
        ans %= mod;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<nax;i++) pe[i] = pp(2, i);
    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}