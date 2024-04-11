#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 1e3;

int a[N];
int n,k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        bool ok = true;
        bool have1 = false;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            ok &= (a[i] == k);
            have1 |= (a[i] == k);
        }
        if (ok) cout << 0 << "\n";
        else {
            int sum = 0;
            for (int i = 1; i <= n; i++) sum += a[i];
            if (sum == n * k || have1) cout << 1 << "\n";
            else cout << 2 << "\n";
        }
    }
    return 0;
}