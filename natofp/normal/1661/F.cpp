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
int sz[nax];
int n;

ll cost(int which, int bonus){
    int parts = bonus + 1;
    ll small = sz[which] / parts;
    int rem = sz[which] % parts;
    int bigCnt = rem;
    int smallCnt = parts - bigCnt;
    ll big = small + 1;
    return (small * small * smallCnt + big * big * bigCnt);
}

int howManyGainsBiggerEqual(int which, ll param){
    if(sz[which] == 1) return 0;
    ll g1 = cost(which, 0);
    ll g2 = cost(which, 1);
    if(g1 - g2 < param) return 0;
    int lo = 1;
    int hi = sz[which] - 1;
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        ll g1 = cost(which, mid);
        ll g2 = cost(which, mid - 1);
        if(g2 - g1 >= param) lo = mid;
        else hi = mid;
    }
    ll splits = lo;
    g1 = cost(which, hi);
    g2 = cost(which, hi - 1);
    if(g2 - g1 >= param) splits = hi;
    return splits;
}

ll totalBiggerEqualGains(ll param){
    ll sum = 0;
    for(int i=1;i<=n;i++) sum += howManyGainsBiggerEqual(i, param);
    return sum;
}

ll m;

ll calcGain(ll param){
    ll gain = 0;
    for(int i=1;i<=n;i++){
        int cnt = howManyGainsBiggerEqual(i, param);
        gain += cost(i, 0) - cost(i, cnt);
    }
    return gain;
}

void solve(){
    cin >> n;
    int last = 0;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        sz[i] = x - last;
        last = x;
    }
    cin >> m;
    ll jest = 0;
    for(int i=1;i<=n;i++) jest += cost(i, 0);
    ll need = jest - m;
    if(need <= 0){
        cout << 0 << "\n";
        return;
    }

    ll lo = 0;
    ll hi = 1e18 + 5;
    while(lo + 1 < hi){
        ll mid = (lo + hi) / 2;
        ll gain = calcGain(mid);
        if(gain < need) hi = mid;
        else lo = mid;
    }

    ll odp = hi;
    ll gain = calcGain(lo);
    if(gain < need) odp = lo;
    gain = calcGain(odp);
    need -= gain;
    ll eq = (need + odp - 2) / (odp - 1);
    if(need == 0) eq = 0;
    cout << totalBiggerEqualGains(odp) + eq << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}