#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, dp[c], maxi;
vector<int> oszt[c], sz;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<c; i++) {
        for (int j=i; j<c; j+=i) {
            oszt[j].push_back(i);
        }
    }
    cin >> w;
    while (w--) {
        cin >> n, maxi=0, sz.clear();
        for (int i=0; i<c; i++) {
            dp[i]=0;
        }
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            sz.push_back(x);
        }
        sort(sz.begin(), sz.end());
        for (int i:sz) {
            int ert=0;
            for (int j:oszt[i]) {
                ert=max(ert, dp[j]);
            }
            dp[i]=ert+1;
            maxi=max(maxi, dp[i]);
        }
        cout << n-maxi << "\n";
    }
    return 0;
}