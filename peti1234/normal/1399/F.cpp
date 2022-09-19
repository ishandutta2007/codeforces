#include <bits/stdc++.h>

using namespace std;
const int c=6002;
int w, n, dp[c][c], t[200002], cnt;
vector<int> v, s[c];
vector<pair<int, int> > sz;
int main()
{
    cin >> w;
    while(w--) {
        for (int i=0; i<v.size(); i++) t[v[i]]=0;
        cin >> n, cnt=0, v.clear(), sz.clear();
        for (int i=0; i<=2*n; i++) {
            s[i].clear();
            for (int j=0; j<=2*n; j++)  dp[i][j]=0;
        }
        for (int i=1; i<=n; i++) {
            int x, y;
            cin >> x >> y;
            sz.push_back({x, y}), v.push_back(x), v.push_back(y);
        }
        sort(v.begin(), v.end()), sort(sz.begin(), sz.end());
        for (int i=0; i<v.size(); i++) {
            if (i==0 || v[i]!=v[i-1]) cnt++;
            t[v[i]]=cnt;
        }
        for (int i=0; i<n; i++) {
            int fi=t[sz[i].first], se=t[sz[i].second];
            dp[fi][se]=1, s[fi].push_back(se);
        }
        for (int j=0; j<=cnt; j++) for (int i=1; i+j<=cnt; i++) {
            int p=i+j, maxi=dp[i+1][p];
            for (int k=0; k<s[i].size(); k++) {
                int l=s[i][k];
                if (l<p) maxi=max(maxi, dp[i][l]+dp[l+1][p]);
            }
            dp[i][p]+=maxi;
        }
        cout << dp[1][cnt] << "\n";
    }
    return 0;
}