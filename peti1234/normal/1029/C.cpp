#include <bits/stdc++.h>

using namespace std;
int n, x, y, sx, sy;
vector<int> kezd, veg;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x >> y;
        if (x>sx) {
            sx=x, sy=y;
        }
        kezd.push_back(x), veg.push_back(y);
    }
    sort(kezd.begin(), kezd.end()), sort(veg.begin(), veg.end());
    if (sy==veg[0]) {
        cout << max(0, veg[1]-kezd[n-2]) << "\n";
    } else {
        cout << max({0, veg[0]-kezd[n-2], veg[1]-kezd[n-1]}) << "\n";
    }
    return 0;
}