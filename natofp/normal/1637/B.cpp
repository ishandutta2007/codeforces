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

const int nax = 105;
int a[nax];
int n;

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int w = j - i + 1;
            for(int k=i;k<=j;k++){
                if(a[k] == 0) w += 1;
            }
            ans += w;
        }
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