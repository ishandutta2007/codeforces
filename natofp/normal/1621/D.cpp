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

const int nax = 555;
int a[nax][nax];
int n;

void solve(){
    cin >> n;
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=2*n;j++) cin >> a[i][j];
    }
    ll ans = 0;
    for(int i=1;i<=n*2;i++){
        for(int j=1;j<=n*2;j++){
            if(i > n && j > n) ans += a[i][j];
        }
    }
    int bonus = 1e9;
    bonus = min(bonus, a[n + 1][1]);
    bonus = min(bonus, a[n * 2][1]);
    bonus = min(bonus, a[n + 1][n]);
    bonus = min(bonus, a[n * 2][n]);
    bonus = min(bonus, a[1][n + 1]);
    bonus = min(bonus, a[1][n * 2]);
    bonus = min(bonus, a[n][n + 1]);
    bonus = min(bonus, a[n][n * 2]);
    cout << ans + bonus << "\n";


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}