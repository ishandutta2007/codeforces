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

const int nax = 1e5 + 5;
int a[nax];
int b[nax];
int n;
int ans[nax];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        int rem = a[i] % 3;
        if(rem == 0) b[i] = 0;
        else b[i] = 1;
    }

    vector<pii> ord;
    for(int i=1;i<=n;i++){
        ord.pb(mp(b[i], i));
    }
    sort(ord.begin(), ord.end());
    int cnt0 = 0;
    for(int i=1;i<=n;i++) cnt0 += (b[i] == 0);
    int z = 0;
    if(cnt0 > n / 2) z = 2;
    cout << z << "\n";
    for(int i=1;i<=n;i++){
        if(i <= n / 2) ans[ord[i - 1].nd] = 1;
    }

    for(int i=1;i<=n;i++) cout << ans[i];
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}