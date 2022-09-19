#include <bits/stdc++.h>

using namespace std;
int w, n, k, dp[77][77], l[77][77], pos;
bool v[77];
vector<pair<pair<int, int>, int> > sz;
vector<int> sol;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> k, pos=k;
        for (int i=1; i<=n; i++) v[i]=0;
        sol.clear(), sz.clear();
        for (int i=1; i<=n; i++) {
            int a, b; cin >> a >> b;
            sz.push_back({{b, a}, i});
        }
        sort(sz.begin(), sz.end());
        for (int i=0; i<n; i++) {
            for (int j=1; j<=i+1; j++) {
                int fi=sz[i].first.first, se=sz[i].first.second, id=sz[i].second, ans=dp[i][j-1]+se+(j-k)*fi;
                dp[i+1][j]=dp[i][j], l[i+1][j]=l[i][j];
                if (j>i || ans>dp[i+1][j]) dp[i+1][j]=ans, l[i+1][j]=id;
            }
        }
        for (int i=n-1; i>=0; i--) if (l[i+1][pos]==sz[i].second) pos--, sol.push_back(sz[i].second), v[sz[i].second]=1;
        cout << 2*n-k << "\n";
        for (int i=k-1; i>=1; i--) cout << sol[i] << " ";
        for (int i=1; i<=n; i++) if (!v[i]) cout << i << " " << -i << " ";
        cout << sol[0] << "\n";
    }
    return 0;
}
/*
1
5 4
86672 371
45367 11927
7218 14839
27951 29919
25534 52009
*/