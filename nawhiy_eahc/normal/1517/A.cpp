#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        if(n%2050)
        {
            cout << "-1\n";
            continue;
        }

        n /= 2050;
        int ans = 0;
        while(n)
        {
            ans += n%10;
            n /= 10;
        }

        cout << ans << "\n";
    }
}