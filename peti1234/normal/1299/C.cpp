#include <bits/stdc++.h>

using namespace std;
int n;
vector<pair<double, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, y=1;
        double z;
        cin >> x, z=x;
        while(sz.size()>0 && z<sz.back().first) {
            double fi=sz.back().first;
            int se=sz.back().second;
            z=(z*y+fi*se)/(y+se);
            y+=se;
            sz.pop_back();
        }
        sz.push_back({z, y});
    }
    cout.precision(11);
    for (int i=0; i<sz.size(); i++) {
        for (int j=0; j<sz[i].second; j++) {
            cout << sz[i].first << " ";
        }
    }
    return 0;
}