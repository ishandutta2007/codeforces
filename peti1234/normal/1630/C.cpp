#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, t[c], kezd[c], veg[c], ans, maxi, ut;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (!kezd[t[i]]) kezd[t[i]]=i;
        veg[t[i]]=i;
    }
    for (int i=1; i<=n; i++) {
        if (kezd[i]) {
            sz.push_back({kezd[i], veg[i]});
        }
    }
    sort(sz.begin(), sz.end());
    for (auto x:sz) {
        if (x.first>maxi) {
            ans++;
            if (ut<maxi) {
                ans++;
            }
            if (x.first!=x.second) {
                ans++;
            }
            ut=x.second, maxi=x.second;
        } else if (x.first>ut) {
            ans++;
            ut=maxi;
        }
        maxi=max(maxi, x.second);
    }
    if (ut!=maxi) {
        ans++;
    }
    cout << n-ans << "\n";
    return 0;
}