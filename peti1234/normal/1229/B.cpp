#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long n, ans, mod=1e9+7, t[c];
vector<int> sz[c];
bool v[c];
void dfs(int a, vector<pair<long long, long long> > p) {
    vector<pair<long long, long long> > s;
    s.push_back({t[a], 1});
    while (p.size()>0 && __gcd(t[a], p.back().first)!=p.back().first) {
        s.push_back({__gcd(t[a], p.back().first), p.back().second});
        p.pop_back();
    }
    while (s.size()>0) {
        if (p.size()==0 || p.back().first!=s.back().first) p.push_back(s.back());
        else p.back().second+=s.back().second;
        s.pop_back();
    }

    for (auto x:p) {
        ans=(ans+x.first*x.second)%mod;
    }

    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x, p);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1, {});
    cout << ans << "\n";
    return 0;
}