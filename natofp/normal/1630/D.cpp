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

const int nax = 1e6 + 5;
int n, m;
ll a[nax];
ll b[nax];

ll mini[nax];
ll cnt[nax];

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> b[i];
    ll g = b[1];
    for(int i=1;i<=m;i++) g = __gcd(g, b[i]);
    if(g == 1){
        ll s = 0;
        for(int i=1;i<=n;i++) s += abs(a[i]);
        cout << s << "\n";
        return;
    }
    ll s = 0;
    for(int i=1;i<=n;i++) s += abs(a[i]);
    ll pay = 2e9;
    fill(mini,mini+n+1,2e9);
    fill(cnt,cnt+n+1,0);
    for(int i=1;i<=n;i++){
        int id = i % g;
        mini[id] = min(mini[id], abs(a[i]));
        if(a[i] < 0) cnt[id] += 1;
    }
    ll spar = 0;
    ll snpar = 0;
    for(int i=0;i<g;i++){
        if(cnt[i] % 2 == 0){
            spar += mini[i];
        }
        else snpar += mini[i];
    }
    pay = min(spar, snpar);
    cout << s - pay * 2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}