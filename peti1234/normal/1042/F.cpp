#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int n, k, ans;
vector<int> sz[c];
bool v[c];
int dfs(int a) {
    v[a]=true;
    if (sz[a].size()==1) {
        return 0;
    }
    vector<int> s;
    for (auto x:sz[a]) {
        if (!v[x]) {
            s.push_back(dfs(x)+1);
        }
    }
    sort(s.rbegin(), s.rend());
    for (int i=1; i<s.size(); i++) {
        if (s[i]+s[i-1]>k) {
            ans++;
        } else {
            return s[i-1];
        }
    }
    return s.back();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (sz[i].size()>1) {
            dfs(i);
            break;
        }
    }
    cout << ans+1 << "\n";
    return 0;
}