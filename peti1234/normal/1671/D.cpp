#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;

    while (w--) {
        long long n, x, kezd, mini, maxi, veg, sum=0, el;
        cin >> n >> x >> kezd;
        mini=maxi=el=veg=kezd;
        for (int i=2; i<=n; i++) {
            cin >> veg;
            sum+=abs(veg-el);
            maxi=max(maxi, veg);
            mini=min(mini, veg);
            el=veg;
        }
        if (mini>1) {
            sum+=min({kezd-1, veg-1, 2*(mini-1)});
        }
        if (maxi<x) {
            sum+=min({x-kezd, x-veg, 2*(x-maxi)});
        }
        cout << sum << "\n";

    }
    return 0;
}
/*
1
3 8
7 2 10
*/