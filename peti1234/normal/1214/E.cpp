#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, t[c], veg;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<2*n; i+=2) {
        int x; cin >> x;
        sz.push_back({x, i});
    }
    sort(sz.rbegin(), sz.rend());
    for (int i=0; i<n; i++) {
        t[i]=sz[i].second;
        if (i) cout << sz[i].second << " " << sz[i-1].second << "\n";
    }
    veg=n-1;
    for (int i=0; i<n; i++) {
        int x=i+sz[i].first-1, id=sz[i].second+1;
        cout << t[x] << " " << id << "\n";
        if (x==veg) {
            veg++;
            t[veg]=id;
        }
    }
    return 0;
}