#include <bits/stdc++.h>

using namespace std;
long long n, xo, x, k, po, ans;
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    po=(1<<k);
    m[0]++;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        xo^=x;
        if (2*xo>=po) {
            xo=po-1-xo;
        }
        ans+=m[xo]/2;
        m[xo]++;
    }
    cout << n*(n+1)/2-ans << "\n";
    return 0;
}