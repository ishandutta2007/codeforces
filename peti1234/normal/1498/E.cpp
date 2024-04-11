#include <bits/stdc++.h>

using namespace std;
int n, t[502], x, y, sum, kezd;
vector<pair<int, int> > sz;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sz.push_back({t[i], i});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<n; i++) {
        int fi=sz[i].first, se=sz[i].second;
        if (!kezd) {
            kezd=se;
        }
        sum+=fi;
        if (i*(i+1)==2*sum) {
            if (kezd!=se) {
                if (abs(t[kezd]-t[se])>=abs(t[x]-t[y])) {
                    x=kezd, y=se;
                }
            }
            kezd=0;
        }
    }
    cout << "! " << x << " " << y << "\n";
    return 0;
}