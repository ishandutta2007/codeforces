#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int w, n, kezd[c], veg[c];
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
            if (!kezd[x]) {
                kezd[x]=i;
            }
            veg[x]=i;
        }
        sort(sz.begin(), sz.end());
        sz.erase(unique(sz.begin(), sz.end()), sz.end());
        int maxi=1, h=1;
        for (int i=1; i<sz.size(); i++) {
            if (kezd[sz[i]]<veg[sz[i-1]]) {
                h=0;
            }
            h++;
            maxi=max(maxi, h);
        }
        int si=sz.size();
        cout << si-maxi << "\n";
        for (auto x:sz) {
            kezd[x]=0, veg[x]=0;
        }
        sz.clear();
    }
    return 0;
}