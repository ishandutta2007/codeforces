#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int n, m, k, db[c], el[c], kov[c], ki[c];
vector<int> sz[c];
bool rossz[c], v[c];

vector<pair<int, long long> > lep;
long long dp[c], mod=998244353;

void dfs(int a) {
    v[a]=true;
    rossz[a]=1;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        int h, pr;
        cin >> h;
        cin >> pr;
        ki[pr]=i;
        for (int j=1; j<h; j++) {
            int x;
            cin >> x;

            sz[x].push_back(pr);
            sz[pr].push_back(x);
            if (ki[x]==i) {
                rossz[x]=1;
            }
            ki[x]=i;
            if (kov[pr] && kov[pr]!=x) {
                rossz[pr]=1;
            }
            if (el[x] && el[x]!=pr) {
                rossz[x]=1;
            }
            kov[pr]=x;
            el[x]=pr;

            pr=x;
        }
    }

    for (int i=1; i<=k; i++) {
        if (rossz[i] && !v[i]) {
            dfs(i);
        }
    }
    for (int i=1; i<=k; i++) {
        if (!rossz[i] && !el[i]) {
            int len=1, pos=i;
            while (kov[pos]) {
                pos=kov[pos];
                len++;
            }
            db[len]++;
            //cout << "ut " << len << "\n";
        }
    }

    for (int i=1; i<=k; i++) {
        if (db[i]) {
            //cout << "fontos " << i << " " << db[i] << "\n";
            lep.push_back({i, db[i]});
        }
    }




    dp[0]=1;
    for (int i=1; i<=m; i++) {
        for (auto x:lep) {
            if (i>=x.first) {
                dp[i]+=dp[i-x.first]*x.second;
            }
        }
        dp[i]%=mod;
    }
    cout << dp[m] << "\n";
    return 0;
}