#include <bits/stdc++.h>

using namespace std;
vector<pair<string, int> > sz;
vector<pair<int, string> > sol;
int n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> s;
        sz.push_back({s, i});
    }
    sort(sz.begin(), sz.end());
    sz.push_back({".", 0});
    for (int i=0; i<n; i++) {
        if (sz[i].first!=sz[i+1].first) sol.push_back({sz[i].second, sz[i].first});
    }
    sort(sol.rbegin(), sol.rend());
    int si=sol.size();
    for (int i=0; i<si; i++) cout << sol[i].second << "\n";
    return 0;
}