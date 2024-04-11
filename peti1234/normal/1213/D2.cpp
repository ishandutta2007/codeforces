#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, k, mini=1e7;
vector<int> sz[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        int x, db=0; cin >> x;
        while(x>0) {
            sz[x].push_back(db);
            db++, x/=2;
        }
    }
    for (int i=0; i<c; i++) {
        sort(sz[i].begin(), sz[i].end());
        int si=sz[i].size();
        if (si>=k) {
            int sum=0;
            for (int j=0; j<k; j++) sum+=sz[i][j];
            mini=min(mini, sum);
        }
    }
    cout << mini << "\n";
    return 0;
}