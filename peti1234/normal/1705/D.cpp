#include <bits/stdc++.h>

using namespace std;
void solve() {
    long long n, sum=0;
    vector<int> sz[2];
    string s[2];
    cin >> n;
    for (int j=0; j<2; j++) {
        cin >> s[j];
        for (int i=1; i<n; i++) {
            if (s[j][i]!=s[j][i-1]) {
                sz[j].push_back(i);
            }
        }
    }
    int si0=sz[0].size(), si1=sz[1].size();
    if (si0!=si1 || s[0][0]!=s[1][0]) {
        cout << -1 << "\n";
        return;
    }
    for (int i=0; i<si0; i++) {
        sum+=abs(sz[0][i]-sz[1][i]);
    }
    cout << sum << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
4 3 1
mark
1 4
5 7
3 8
12
*/