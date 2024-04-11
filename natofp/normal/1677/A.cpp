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

using namespace std;

const int nax = 5005;
int a[nax];
int n;
ll mniejsze[nax];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    ll ans = 0;
    fill(mniejsze + 1, mniejsze + n + 1, 0);
    for(int i=1;i<=n;i++){
        ll suf = 0;
        for(int j=n;j>i;j--){
            ans += suf * mniejsze[a[j] - 1];
            suf += (a[j] < a[i]);
        }
        for(int j=a[i];j<=n;j++) mniejsze[j] += 1;
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