#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    int n;
    cin >> n;
    ll ans = 0;
    ll c = n-1;
    for(int j = 1;j<=n;j++){
        ans += c*j;
        c--;
    }
    ans+=n;
    cout << ans;
    return 0;
}