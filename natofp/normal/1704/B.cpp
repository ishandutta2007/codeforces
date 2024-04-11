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

const int nax = 2e5 + 5;
int a[nax];
int n, x;

void solve(){
    cin >> n >> x;
    for(int i=1;i<=n;i++) cin >> a[i];
    int ans = 0;
    int wsk = 1;
    while(wsk <= n){
        int mini = a[wsk];
        int maxi = a[wsk];
        while(wsk <= n && maxi - mini <= x * 2){
            wsk++;
            if(wsk == n + 1) break;
            mini = min(mini, a[wsk]);
            maxi = max(maxi, a[wsk]);
        }
        ans++;
    }
    cout << ans - 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}