#include <bits/stdc++.h>

using namespace std;
long double pi=acos(-1);
int n, pos=0;
vector<pair<long double, int> > sz;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        long double x, y;
        cin >> x >> y;
        long double ert=acos(x/sqrt(x*x+y*y));
        if (y<0) {
            ert=2*pi-ert;
        }
        sz.push_back({ert, i});
    }
    sort(sz.begin(), sz.end());
    sz.push_back({sz[0].first+2*pi, sz[0].second});
    for (int i=1; i<n; i++) {
        if (sz[i+1].first-sz[i].first<sz[pos+1].first-sz[pos].first) {
            pos=i;
        }
    }
    cout << sz[pos].second << " " << sz[pos+1].second << "\n";
    return 0;
}