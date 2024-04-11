#include <bits/stdc++.h>
#define ll long long int
#define rep(i,l,r) for(ll i=l; i<r; i++)
#define X first
#define Y second
using namespace std;
const ll N=1e7;
ll h[N],cnt[N];
int main(){
    ll n,sum = 0,ans = 0;
    cin >> n;
    if (n == 1 || n == 3 || n == 4){
        cout << 0 << endl;
        return 0;
    }
    if (n == 2 || n == 5){
        cout << 1;
        return 0;
    }
    rep (i,1,n){
        sum+=3*i-1;
        if (sum > n) break;
        if (n % 3 == 1 && i%3 == 2){
            ans++;
        }
        if (n%3 == 0 && i%3 == 0){
            ans++;
        }
        if (n%3 == 2 && i%3 == 1){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}