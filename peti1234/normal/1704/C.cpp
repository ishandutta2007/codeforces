#include <bits/stdc++.h>

using namespace std;
bool solve() {
    int n, m, t[100005];
    vector<int> sz;
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> t[i];
    }
    sort(t+1, t+m+1);
    for (int i=2; i<=m; i++) {
        sz.push_back(t[i]-t[i-1]-1);
    }
    sz.push_back(t[1]+n-t[m]-1);
    int ans=0, cnt=0;
    sort(sz.rbegin(), sz.rend());
    for (auto x:sz) {
        int s=x-cnt;
        if (s==1) ans++;
        if (s>1) ans+=s-1;
        cnt+=4;
    }
    cout << n-ans << "\n";
}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}