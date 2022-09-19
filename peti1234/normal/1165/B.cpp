#include <bits/stdc++.h>

using namespace std;
int n, ans;
vector<int> sz;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        sz.push_back(x);
    }
    sort(sz.begin(), sz.end());
    for (auto x:sz) {
        if (x>ans) ans++;
    }
    cout << ans << "\n";
    return 0;
}