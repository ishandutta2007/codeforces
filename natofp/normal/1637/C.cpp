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

const int nax = 1e5 + 5;
int a[nax];
int n;

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    ll ans = 0;
    ll npar = 0;
    for(int i=2;i<n;i++){
        if(a[i] % 2 == 1) npar += 1;
        ans += (a[i] + 1) / 2;
    }
    bool ruch = false;
    for(int i=2;i<n;i++){
        if(a[i] > 1) ruch = true;
    }
    if(n == 3 && a[2] % 2 == 1) ruch = false;
    if(npar > 0 && ruch == false) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}