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

const int mod = 998244353;
const int nax = 1e6 + 5;
int n, k;
int a[nax];

int dokladnie[nax];
int maksymalnie[nax];

void solve(){
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    fill(dokladnie + 1, dokladnie + n + 1, -1);
    fill(maksymalnie + 1, maksymalnie + n + 1, -1);
    for(int i=1;i<=n;i++){
        if(a[i] == -1) continue;
        if(a[i] > 0){
            if(i + k > n){
                cout << 0 << "\n";
                return;
            }
            dokladnie[i + k] = a[i] + k;
        }
        else{
            if(i + k <= n) maksymalnie[i + k] = k;
        }
    }
    ll ans = 1;
    for(int i=1;i<=n;i++){
        if(maksymalnie[i] == -1 && dokladnie[i] == -1){
            ans *= i;
            ans %= mod;
        }
        else if(maksymalnie[i] >= 0){
            int ile = min(i - 1, maksymalnie[i]);
            ans *= (ile + 1);
            ans %= mod;
        }
        else if(dokladnie[i]){
            continue;
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