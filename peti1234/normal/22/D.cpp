#include <bits/stdc++.h>

using namespace std;
int n, mini=1e6;
vector<pair<int, int> > sz;
vector<int> sol;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b; cin >> a >> b;
        if (a>b) {
            swap(a, b);
        }
        sz.push_back({a, b});
    }
    sort(sz.begin(), sz.end());
    for (pair<int, int> i:sz) {
        if (i.first>mini) {
            sol.push_back(mini);
            mini=1e6;
        }
        mini=min(mini, i.second);
    }
    sol.push_back(mini);
    cout << sol.size() << "\n";
    for (int i:sol) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}