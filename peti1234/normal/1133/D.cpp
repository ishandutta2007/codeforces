#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, a[c],maxi, spec;
map<pair<long long, long long>, long long> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        long long x=a[i], y;
        cin >> y;
        if (x==0) {
            if (y==0) spec++;
            continue;
        }
        long long s=__gcd(x, y);
        x/=s, y/=s;
        if (x<0) x*=-1, y*=-1;
        maxi=max(maxi, ++m[{x, y}]);
    }
    cout << maxi+spec << "\n";
    return 0;
}