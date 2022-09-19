#include <bits/stdc++.h>

using namespace std;
map<int, int> sz;
int w, n, maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        sz.clear(), maxi=0;
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sz[x]++;
            maxi=max(maxi, sz[x]);
        }
        cout << max(n%2, 2*maxi-n) << "\n";
    }
    return 0;
}