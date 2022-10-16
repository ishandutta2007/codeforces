#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

void solve(){
    int n; cin >> n;
    if(n & 1){
        cout << "NO" << "\n";
        return;
    }
    n /= 2;
    int x = sqrt(n);
    if(x * x == n){
        cout << "YES" << "\n";
        return;
    }
    if(n & 1){
        cout << "NO" << "\n";
        return;
    }
    n /= 2;
    x = sqrt(n);
    if(x * x == n) cout << "YES" << "\n";
    else cout << "NO" << "\n";


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}