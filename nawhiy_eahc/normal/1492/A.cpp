#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll p, a, b, c;
        cin >> p >> a >> b >> c;
        ll ans = a - (p%a == 0 ? a : p%a);
        ans = min(ans, b - (p%b == 0? b : p%b));
        ans = min(ans, c - (p%c == 0? c : p%c));

        cout << ans << "\n";
    }
}