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
int a[nax];
int n;
int pot[nax];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        int c = 0;
        int tmp = a[i];
        while(tmp % 2 == 0){
            tmp /= 2;
            c += 1;
        }
        pot[i] = c;
    }

    const int mod = 1e9 + 7;
    int zeros = 0;
    for(int i=1;i<=n;i++){
        zeros += (pot[i] == 0);
    }
    ll bad = 1;
    for(int i=0;i<n-zeros;i++){
        bad *= 2;
        bad %= mod;
    }
    ll all = 1;
    for(int i=1;i<=n;i++){
        all *= 2;
        all %= mod;
    }
    ll ans = all - bad;
    if(ans < 0) ans += mod;
    for(int m=1;m<30;m++){
        ll cnt = 0;
        ll cntBigger = 0;
        for(int i=1;i<=n;i++){
            if(pot[i] == m) cnt += 1;
            if(pot[i] > m) cntBigger += 1;
        }
        ll ways = 1;
        for(int i=0;i<cnt-1;i++){
            ways *= 2;
            ways %= mod;
        }
        ways -= 1;
        if(ways < 0) ways += mod;
        // choose minimums to parity
        ll rst = 1;
        for(int i=0;i<cntBigger;i++){
            rst *= 2;
            rst %= mod;
        }
        ways *= rst;
        ways %= mod;
        ans += ways;
        ans %= mod;
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