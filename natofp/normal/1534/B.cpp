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

const int nax = 4e5 + 5;
ll a[nax];
ll b[nax];

void solve(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    a[n + 1] = 0;
    ll ans = 0;
    for(int i=1;i<n;i++){
        ans += abs(a[i] - a[i + 1]);
    }
    ans += a[1];
    ans += a[n];
    for(int i=1;i<=n;i++){
        ll ma = max(a[i - 1], a[i + 1]);
        if(a[i] > ma){
            ans -= (a[i] - ma);
        }
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