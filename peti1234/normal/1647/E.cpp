#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, t[c][30], pos[c], cel[c], db[c], ans[c], maxi, u, ert;
priority_queue<int> q;
vector<int> sz[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i][0];
        db[t[i][0]]++;
        if (db[t[i][0]]>1) {
            u++;
        }
    }
    for (int i=1; i<30; i++) {
        for (int j=1; j<=n; j++) {
            t[j][i]=t[t[j][i-1]][i-1];
        }
    }
    for (int i=1; i<=n; i++) {
        cin >> pos[i];
        maxi=max(maxi, pos[i]);
        if (pos[i]<=n) {
            cel[pos[i]]=i;
        }
    }
    ert=(maxi-n)/u;
    for (int i=1; i<=n; i++) {
        int p=i;
        for (int j=0; j<30; j++) {
            if (ert & (1<<j)) {
                p=t[p][j];
            }
        }
        //cout << "par " << p << " " << i << "\n";
        sz[p].push_back(i);
    }
    for (int i=1; i<=n; i++) {
        sort(sz[i].begin(), sz[i].end());
    }
    for (int i=1; i<=n; i++) {
        if (cel[i]) {
            ans[sz[cel[i]][0]]=i;
            for (int j=1; j<sz[cel[i]].size(); j++) {
                q.push(-sz[cel[i]][j]);
            }
        } else {
            ans[-q.top()]=i;
            q.pop();
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}