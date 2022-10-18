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
    for(int i=1;i<=n;i++) cin >> a[i];
    int ans = 1e9;
    if(n == 1) ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int len = j - i;
            int dif = a[j] - a[i];
            int good = 0;
            for(int k=1;k<=n;k++){

                int licz = (i - k) * dif;
                if(abs(licz) % len != 0) continue;
                int ex = (i - k) * dif / len;
                ex = a[i] - ex;
                if(ex == a[k]) good += 1;
                //if(a[k] == fi + (k - 1) * dif) good += 1;
            }
            ans = min(ans, n - good);
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