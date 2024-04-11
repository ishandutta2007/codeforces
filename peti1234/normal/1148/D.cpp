#include <bits/stdc++.h>

using namespace std;
int n;
vector<pair<int, int> > a, b;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        if (y>x) {
            a.push_back({x, i});
        } else {
            b.push_back({y, i});
        }
    }
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    if (a.size()>b.size()) {
        cout << a.size() << "\n";
        for (int i=0; i<a.size(); i++) {
            cout << a[i].second << " ";
        }
    } else {
        cout << b.size() << "\n";
        for (int i=0; i<b.size(); i++) {
            cout << b[i].second << "\n";
        }
    }
    return 0;
}