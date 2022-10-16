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
ll l[nax];
ll r[nax];
ll c[nax];

void solve(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> l[i] >> r[i] >> c[i];
    multiset<int> L, R, LR;
    ll minL = 2e9;
    ll maxR = -2e9;
    for(int i=1;i<=n;i++){
        if(l[i] < minL){
            L.clear();
            LR.clear();
        }
        if(r[i] > maxR){
            R.clear();
            LR.clear();
        }

        if(l[i] <= minL) L.insert(c[i]);
        if(r[i] >= maxR) R.insert(c[i]);
        if(l[i] <= minL && r[i] >= maxR) LR.insert(c[i]);
        minL = min(minL, l[i]);
        maxR = max(maxR, r[i]);
        int ans = 2e9;
        ans = (*L.begin()) + (*R.begin());
        if(LR.size()){
            ans = min(ans, (*LR.begin()));
        }
        cout << ans << "\n";
    }


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}