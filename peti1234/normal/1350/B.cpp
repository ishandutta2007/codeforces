#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int w, n, maxi, t[c], dp[c];
vector<int> oszt[c];
int main()
{
    cin >> w;
    for (int i=1; i<c; i++) for (int j=2*i; j<c; j+=i) oszt[j].push_back(i);
    while(w--) {
        cin >> n, maxi=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i], dp[i]=1;
            for (int j=0; j<oszt[i].size(); j++) if (t[i]>t[oszt[i][j]]) dp[i]=max(dp[i], dp[oszt[i][j]]+1);
            maxi=max(maxi, dp[i]);
        }
        cout << maxi << "\n";
    }
    return 0;
}