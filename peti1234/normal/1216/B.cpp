#include <bits/stdc++.h>

using namespace std;
int n, sum;
vector<pair<int, int> > sz;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sz.push_back({x, i});
    }
    sort(sz.rbegin(), sz.rend());
    for (int i=0; i<n; i++) {
        sum+=i*sz[i].first+1;
    }
    cout << sum << "\n";
    for (auto x:sz) {
        cout << x.second << " ";
    }
    cout << "\n";
    return 0;
}