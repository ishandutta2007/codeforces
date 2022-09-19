#include <bits/stdc++.h>

using namespace std;
void solve() {
    long long sum=0;
    vector<int> sz;
    int n;
    string s;
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        if (s[i]=='L') {
            sum+=i;
            sz.push_back(max(0, n-1-i-i));
        } else {
            sum+=n-1-i;
            sz.push_back(max(0, i+i+1-n));
        }
    }
    sort(sz.rbegin(), sz.rend());
    for (int i=0; i<n; i++) {
        sum+=sz[i];
        cout << sum << " ";
    }
    cout << "\n";
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