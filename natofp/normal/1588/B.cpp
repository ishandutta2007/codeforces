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

ll ask(int l, int r){
    cout << "? " << l << " " << r << endl;
    fflush(stdout);
    ll ans; cin >> ans;
    return ans;
}

ll binom(ll n){
    return (n * (n - 1)) / 2;
}

ll idiota(ll k){
    ll lo = 1;
    ll hi = 1e9;
    while(lo + 1 < hi){
        ll mid = (lo + hi) / 2;
        if(binom(mid) > k) hi = mid;
        else lo = mid;
    }
    for(ll i=lo;i<=hi;i++){
        if(binom(i) == k) return i;
    }
}

void solve(){
    int n; cin >> n;
    ll lo = 1;
    ll hi = n;
    while(lo + 1 < hi){
        ll mid = (lo + hi) / 2;
        ll cnt = ask(1, mid);
        if(cnt == 0) lo = mid;
        else hi = mid;
    }
    ll emp = lo;
    if(ask(1, hi) == 0) emp = hi;
    // [1 .... emp] is empty
    ll all = ask(1, n);
    // i = emp
    ll debil = ask(emp + 1, n);
    ll gone = all - debil;
    ll fiLen = gone + 1;
    all -= binom(fiLen);
    ll seLen = idiota(all);
    cout << "! " << emp << " " << emp + fiLen << " " << emp + fiLen + seLen - 1 << endl;
    fflush(stdout);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}