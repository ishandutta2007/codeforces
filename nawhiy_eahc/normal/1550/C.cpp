#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[200002];

bool good(int a, int b, int c)
{
    if(a <= b && b <= c) return false;
    if(a >= b && b >= c) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        if(n == 1)
        {
            cout << "1" << "\n";
            continue;
        }
        if(n == 2)
        {
            cout << "3" << "\n";
            continue;
        }

        int ans = 2 * n - 1;

        for(int i=1;i<=n-2;i++)
        {
            if(good(a[i], a[i+1], a[i+2])) ans++;
        }

        for(int i=1;i<=n-3;i++)
        {
            if(good(a[i], a[i+1], a[i+2]) && good(a[i], a[i+1], a[i+3]) && good(a[i], a[i+2], a[i+3]) && good(a[i+1], a[i+2], a[i+3])) ans++;
        }

        cout << ans << "\n";
    }
}