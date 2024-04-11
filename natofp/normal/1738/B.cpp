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
ll a[nax];
int n, k;

void solve(){
    cin >> n >> k;
    for(int i=1;i<=k;i++) cin >> a[i];
    ll last = 2e9 + 2e8;
    for(int i=k-1;i>=1;i--){
        ll cur = a[i + 1] - a[i];
        if(cur > last){
            cout << "No" << "\n";
            return;
        }
        last = cur;
    }
    ll need = n - k + 1;
    if(a[1] - need * last <= 0) cout << "Yes" << "\n";
    else cout << "No" << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}