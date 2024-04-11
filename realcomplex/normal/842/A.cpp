#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    ll l,r,a,b,k;
    cin >> l >> r >> a >> b >> k;
    for(ll j = a;j<=b;j++){
        if(k*j >= l && k*j <= r){
            cout << "YES";
            exit(0);
        }
    }
    cout << "NO";
    return 0;
}