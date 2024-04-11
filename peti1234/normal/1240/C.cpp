#include <bits/stdc++.h>

using namespace std;
const int c=500005;
long long w, n, k, sum;
vector<int> sz[c], s[c];
bool v[c];
int dfs(int a) {
    vector<int> le;
    v[a]=true;

    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=s[a][i];
        if (!v[x]) {
            int ert=dfs(x);
            sum+=ert;
            le.push_back(y-ert);
        }
    }

    sort(le.rbegin(), le.rend());
    for (int i=0; i<le.size(); i++) {
        if (i<k-1) {
            sum+=max(0, le[i]);
        }
    }

    if (le.size()<k) {
        return 0;
    }
    return max(0, le[k-1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            sz[a].push_back(b), s[a].push_back(c);
            sz[b].push_back(a), s[b].push_back(c);
        }

        cout << sum+dfs(1) << "\n";
        for (int i=1; i<=n; i++) {
            sz[i].clear(), s[i].clear();
            v[i]=0;
        }
        sum=0;
    }
    return 0;
}