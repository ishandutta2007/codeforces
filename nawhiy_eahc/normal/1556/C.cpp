#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[1002];


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    ll ans = 0;

    for(int i=1;i<=n;i+=2)
    {
        ll x = 0, y = 0;
        if(i == n) break;
        ans--;
        for(int j=i+1;j<=n;j+=2)
        {
            ans += max(min(a[j] - y, a[i] - x) + 1, 0LL);
            if(y > a[j]) y -= a[j];
            else { x += a[j] - y; y = 0; }
            y += a[j+1];
        }
    }

    cout << ans << "\n";
}