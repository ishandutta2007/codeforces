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

vector<ll> a[3];
int c[3];

ll ans = 4e18;

ll sq(ll x){
    return x * x;
}

void go(vector<ll> x, vector<ll> y, vector<ll> z){
    int p1 = 0;
    int p2 = 0;
    for(int i=0;i<y.size();i++){
        ll cur = y[i];
        while(p1 + 1 < x.size() && x[p1 + 1] <= cur) p1++;
        while(p2 < z.size() && z[p2] < cur) p2++;
        if(p2 == z.size()) return;
        if(x[p1] > cur) continue;
        ans = min(ans, sq(cur - x[p1]) + sq(cur - z[p2]) + sq(x[p1] - z[p2]));
    }
}

void solve(){
    ans = 4e18;
    for(int i=0;i<3;i++) cin >> c[i];
    for(int i=0;i<3;i++){
        a[i].clear();
        for(int j=0;j<c[i];j++){
            int x; cin >> x;
            a[i].pb(x);
        }
        sort(a[i].begin(), a[i].end());
    }
    go(a[0], a[1], a[2]);
    go(a[0], a[2], a[1]);
    go(a[1], a[0], a[2]);
    go(a[1], a[2], a[0]);
    go(a[2], a[0], a[1]);
    go(a[2], a[1], a[0]);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}