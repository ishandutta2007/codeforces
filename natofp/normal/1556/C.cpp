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

const int nax = 1005;
ll a[nax];
int n;

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    ll ans = 0;
    for(int i=1;i<=n;i+=2){
        ll lo = 1;
        ll hi = a[i];
        for(int j=i+1;j<=n;j++){
            if(j % 2 == 0){
                ll canEnd = min(hi, a[j]) - lo + 1;
                canEnd = max(canEnd, 0LL);
                ans += canEnd;
                lo -= a[j];
                hi -= a[j];
                lo = max(lo, 0LL);
            }
            else{
                lo += a[j];
                hi += a[j];
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}