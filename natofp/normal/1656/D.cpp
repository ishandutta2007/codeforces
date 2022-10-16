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



void solve(){
    ll n; cin >> n;
    ll tmp = n * 2;
    ll xd = 1;
    while(tmp % 2 == 0){
        tmp /= 2;
        xd *= 2;
    }

    if(xd <= 2e9){
        ll mam = xd * (xd - 1) / 2;
        if(mam < n){
            cout << xd << "\n";
            return;
        }
    }

    // np ?

    tmp = n;
    while(tmp % 2 == 0) tmp /= 2;
    if(tmp <= 2e9){
        ll xd = tmp;
        ll mam = xd * (xd - 1) / 2;
        if(mam < n && xd != 1){
            cout << xd << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}