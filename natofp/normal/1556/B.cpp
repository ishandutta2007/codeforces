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
int b[nax];
int opt[nax];
int c[2];
int n;

ll cost(){
    vector<int> posb, posopt;
    for(int i=1;i<=n;i++){
        if(b[i] == 1) posb.pb(i);
        if(opt[i] == 1) posopt.pb(i);
    }
    ll ac = 0;
    for(int i=0;i<posb.size();i++){
        ac += abs(posb[i] - posopt[i]);
    }
    return ac;
}

void solve(){
    c[0] = 0;
    c[1] = 0;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        x = abs(x);
        a[i] = x % 2;
        c[x & 1]++;
    }
    if(c[1] != (n + 1) / 2 && c[1] != n / 2){
        cout << -1 << "\n";
        return;
    }
    ll ans = 1e18;
    if(c[1] == c[0]){
        for(int i=1;i<=n;i++){
            opt[i] = (i & 1);
        }
        for(int i=1;i<=n;i++) b[i] = a[i];
        ans = min(ans, cost());

        for(int i=1;i<=n;i++){
            opt[i] = 1 - (i & 1);
        }
        for(int i=1;i<=n;i++) b[i] = a[i];
        ans = min(ans, cost());
    }
    else{
        if(c[0] > c[1]){
            for(int i=1;i<=n;i++){
                if(i % 2 == 1) opt[i] = 0;
                else opt[i] = 1;
            }
        }
        else{
           for(int i=1;i<=n;i++){
                if(i % 2 == 1) opt[i] = 1;
                else opt[i] = 0;
            }
        }
        for(int i=1;i<=n;i++) b[i] = a[i];
        ans = min(ans, cost());
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