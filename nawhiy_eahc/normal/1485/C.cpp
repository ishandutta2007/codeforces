#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll x, y, i;
        ll ans = 0;
        cin >> x >> y;
        if(y * y - 1 <= x){
            cout << ((y-1) * y)/2 << "\n";
            continue;
        }
        for(i=2;i*i - 1<=x;i++){
            ans += (i-1);
        }

        ll cur = i - 1;

        for(ll j = i - 2;j >= 1; j--){
            ll next = min(y, x/j - 1);
            ans += (next - cur) * j;
            cur = next;
        }

        cout << ans << "\n";
    }
}