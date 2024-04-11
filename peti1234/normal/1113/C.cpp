#include <bits/stdc++.h>

using namespace std;
const int c=1050002;
long long ox[c], ex[c], n, ans, xo;
int main()
{
    cin >> n;
    ex[0]=1;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        xo^=x;
        if (i%2) ans+=ox[xo], ox[xo]++;
        else ans+=ex[xo], ex[xo]++;
    }
    cout << ans << "\n";
    return 0;
}