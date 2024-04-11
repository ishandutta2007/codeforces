#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, m, dp[c], db[c], cnt, sum, ans=c;
vector<int> sz[c];
bool v[c], jo[c];
vector<pair<int, int> > ert;
void dfs(int a) {
    v[a]=true;
    cnt++;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        dp[i]=c;
        int x=i, p=1;
        while(x) {
            if (x%10!=4 && x%10!=7) {
                p=0;
            }
            x/=10;
        }
        if (p) {
            jo[i]=1;
        }
    }
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            cnt=0;
            dfs(i);
            db[cnt]++;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; db[i]>0; j*=2) {
            int mini=min(j, db[i]);
            ert.push_back({i*mini, mini});
            db[i]-=mini;
        }
    }
    sort(ert.begin(), ert.end());
    for (pair<int, int> x:ert) {
        int fi=x.first, se=x.second;
        for (int i=sum; i>=0; i--) {
            dp[i+fi]=min(dp[i+fi], dp[i]+se);
        }
        sum+=fi;
    }
    for (int i=1; i<=n; i++) {
        if (jo[i]) {
            ans=min(ans, dp[i]);
        }
    }
    cout << (ans==c? -1 : ans-1) << endl;
    return 0;
}