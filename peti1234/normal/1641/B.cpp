#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > ans;
vector<int> spl;
bool solve(vector<int> sz, int pos) {
    int si=sz.size(), x=0;
    if (si==0) {
        return true;
    }
    for (int i=1; i<si; i++) {
        if (sz[i]==sz[0]) {
            x=i;
            break;
        }
    }
    if (!x) {
        return false;
    }
    vector<int> kov;
    for (int i=1; i<x; i++) {
        ans.push_back({pos+x+i, sz[i]});
        kov.push_back(sz[i]);
    }
    spl.push_back(2*x);
    reverse(kov.begin(), kov.end());
    for (int i=x+1; i<si; i++) {
        kov.push_back(sz[i]);
    }
    return solve(kov, pos+2*x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n;
        vector<int> sz;
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
        }
        if (solve(sz, 0)) {
            cout << ans.size() << "\n";
            for (auto x:ans) {
                cout << x.first << " " << x.second << "\n";
            }
            cout << spl.size() << "\n";
            for (auto x:spl) {
                cout << x << " ";
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
        ans.clear(), spl.clear();
    }
    return 0;
}