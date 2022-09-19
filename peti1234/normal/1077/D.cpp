#include <bits/stdc++.h>

using namespace std;
int n, k;
map<int, int> m;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    for (auto p:m) {
        int a=p.first, b=p.second;
        for (int i=1; i<=b; i++) {
            sz.push_back({b/i, a});
        }
    }
    sort(sz.rbegin(), sz.rend());
    for (int i=0; i<k; i++) {
        cout << sz[i].second << " ";
    }
    cout << "\n";
    return 0;
}