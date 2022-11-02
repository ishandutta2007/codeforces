#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll l,r;
    cin >> l >> r;
    ll cnt = 62;
    while(cnt >= 0 && (l & ((ll)1 << cnt)) == (r & ((ll) 1 << cnt))) cnt--;
    cout << ((ll)1 << (cnt + 1)) - 1;
}