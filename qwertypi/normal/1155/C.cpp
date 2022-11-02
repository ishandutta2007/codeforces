#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int main(){
    ll n, m;
    cin >> n >> m;
    ll init;
    cin >> init;
    ll gcd = 0;
    for(ll i=1;i<n;i++){
        ll k;
        cin >> k;
        gcd = __gcd(gcd, k-init);
    }
    for(ll i=0;i<m;i++){
        ll k;
        cin >> k;
        if(gcd % k == 0){
            cout << "YES" << endl;
            cout << init << ' ' << i+1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}