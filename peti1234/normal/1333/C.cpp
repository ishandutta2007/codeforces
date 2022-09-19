#include <bits/stdc++.h>

using namespace std;
long long n, ut, sum, kom[200002], el[200002];
vector<pair<long long, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n, sum=n*(n+1)/2;
    for (int i=1; i<=n; i++) cin >> kom[i], kom[i]+=kom[i-1], sz.push_back({kom[i], i});
    sz.push_back({0, 0}), sort(sz.begin(), sz.end());
    for (int i=1; i<=n; i++) if (sz[i].first==sz[i-1].first) el[sz[i].second]=sz[i-1].second+1;
    for (int i=1; i<=n; i++) ut=max(el[i], ut), sum-=ut;
    cout << sum << "\n";
    return 0;
}
// Knny volt.