#include <bits/stdc++.h>

using namespace std;
const int c=500005;
long long n, mini, rf[c], dp[c], sok=1e12;
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    rf[a]=1;
    vector<pair<long long, long long> > s;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            rf[a]+=rf[x];
            s.push_back({rf[x], dp[x]});
        }
    }
    sort(s.rbegin(), s.rend());
    int si=min((int)s.size(), 100);
    for (int i=0; i<si; i++) {
        for (int j=i+1; j<si; j++) {
            long long ert=n-s[i].first-s[j].first;
            mini=min(mini, s[i].second+s[j].second+ert*ert);
        }
    }
    dp[a]=rf[a]*rf[a];
    for (auto x:s) {
        dp[a]=min(dp[a], (rf[a]-x.first)*(rf[a]-x.first)+x.second);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    if (n==2) {
        cout << 2 << "\n";
        return 0;
    }
    mini=sok;
    for (int i=1; i<=n; i++) {
        if (sz[i].size()>1) {
            dfs(i);
            break;
        }
    }
    cout << n*n-(mini-n)/2-n << "\n";
    return 0;
}