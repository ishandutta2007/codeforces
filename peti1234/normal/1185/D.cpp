#include <bits/stdc++.h>

using namespace std;
int n;
vector<pair<int, int> > sz;
void ans(int x) {
    cout << x << "\n";
    exit(0);
}
void solve(int x) {
    int cnt=0;
    for (int i=1; i<n; i++) {
        if (sz[i].first-sz[i-1].first==x) {
            cnt++;
        }
    }
    if (cnt==n-1) {
        ans(sz[0].second);
    }
    if (cnt==n-2) {
        if (sz[1].first-sz[0].first!=x) ans(sz[0].second);
        if (sz[n-1].first-sz[n-2].first!=x) ans(sz[n-1].second);
    }
    for (int i=1; i<n-1; i++) {
        int a=sz[i].first-sz[i-1].first, b=sz[i+1].first-sz[i].first, c=a+b;
        if (c==x) {
            if (cnt==n-3 && a!=x || cnt==n-2 && c>0) ans(sz[i].second);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sz.push_back({x, i});
    }
    sort(sz.begin(), sz.end());
    if (n<=3) {
        ans(1);
    }
    solve(sz[1].first-sz[0].first);
    solve(sz[n-1].first-sz[n-2].first);
    ans(-1);
    return 0;
}