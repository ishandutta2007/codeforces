#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, k;
long double r[c], dir[c], pi=acos(-1);
int calc(long double ert) {
    vector<pair<long double, int> > sz;
    for (int i=1; i<=n; i++) {
        if (r[i]<=2*ert) {
            long double dif=acos(r[i]/(2*ert));
            sz.push_back({dir[i]-dif, 1});
            sz.push_back({dir[i]-dif+2*pi, 1});

            sz.push_back({dir[i]+dif, -1});
            sz.push_back({dir[i]+dif+2*pi, -1});
        }
    }
    sort(sz.begin(), sz.end());
    int cnt=0, maxi=0;
    for (auto x:sz) {
        cnt+=x.second;
        maxi=max(maxi, cnt);
    }
    return maxi;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        long double x, y;
        cin >> x >> y;
        r[i]=sqrt(x*x+y*y);
        if (r[i]<0.5) {
            r[i]=1e18, k--;
            continue;
        }
        long double ert=acos(x/r[i]);
        if (y<0) {
            ert=2*pi-ert;
        }
        dir[i]=ert;
    }
    long double lo=0, hi=2e5, mid;
    while (hi-lo>1e-5) {
        mid=(hi+lo)/2;
        if (calc(mid)>=k) {
            hi=mid;
        } else {
            lo=mid;
        }
    }
    cout.precision(10);
    cout << hi << "\n";
    return 0;
}