#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, x, y, cnt, ans;
vector<int> sz[c];
bool v[c];
bool dfs(int a) {
    v[a]=true;
    int db=0;
    for (auto x:sz[a]) {
        if (!v[x]) {
            db+=dfs(x);
        }
    }
    db=min(db, 2);
    cnt+=db;
    return (db<2);
}
int main()
{
    cin >> n >> x >> y;
    ans=(n-1)*y;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    if (x>y) {
        int maxi=0;
        for (int i=1; i<=n; i++) {
            int si=sz[i].size();
            maxi=max(maxi, si);
        }
        if (maxi==n-1) {
            ans+=(x-y);
        }
    } else {
        dfs(1);
        ans+=cnt*(x-y);
    }
    cout << ans << "\n";
    return 0;
}