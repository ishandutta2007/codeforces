#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main(){

    ll n,x;
    cin >> n >> x;
    ll sk[n];
    for(int j = 0;j<n;j++){
        cin >> sk[j];
    }
    sort(sk,sk+n);
    ll ans = 0;
    for(int j = 0;j<n;j++){
        ans += sk[j]*x;
        x = max(ll(1),x-1);
    }
    cout << ans;
    return 0;
}