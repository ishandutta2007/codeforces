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
#define mt make_tuple
#define pch pair<char, char>

using namespace std;

const int nax = 1505;
pii go[nax * nax];
ll r[nax];
ll c[nax];
ll n;

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x; cin >> x;
            go[x] = mp(i, j);
        }
    }

    ll ans = 0;
    for(int i=1;i<=n*n;i++){
        int rr = go[i].st;
        int cc = go[i].nd;
        ans += r[rr] * c[cc];
        r[rr]++;
        c[cc]++;
    }
    ans = n * (n - 1) * n * (n - 1) / 2 - ans;
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}