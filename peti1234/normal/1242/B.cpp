#include <bits/stdc++.h>

using namespace std;
const int c=100005;
vector<int> sz[c], q;
int db[c], n, m, ans, ff=2, si=0;
bool v[c];
void pb(int a) {
    si++;
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        db[x]++;
    }
}
void ker() {
    for (int i=1; i<=n; i++) {
        if (!v[i] && si>db[i]) {
            q.push_back(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    pb(1);
    while(si<n) {
        ker();
        for (int i=0; i<q.size(); i++) {
            pb(q[i]);
        }
        if (q.size()==0) {
            while(v[ff]) {
                ff++;
            }
            ans++;
            pb(ff);
        }
        q.clear();
    }
    cout << ans << "\n";
    return 0;
}