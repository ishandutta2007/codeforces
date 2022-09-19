#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long k, cnt=1;
int n, m, szint[c];
vector<int> v[c];
vector<pair<int, int> > sz[c];
bool ans[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back({b, i}), sz[b].push_back({a, i});
    }
    szint[1]=1;
    queue<int> q;
    q.push(1);
    while (q.size()>0) {
        auto a=q.front();
        q.pop();
        if (a!=1) {
            long long si=v[a].size();
            cnt=min(k, cnt*si);
        }
        for (auto p:sz[a]) {
            int x=p.first, y=p.second;
            if (!szint[x]) {
                szint[x]=szint[a]+1;
                q.push(x);
            }
            if (szint[x]==szint[a]+1) {
                v[x].push_back(y);
            }
        }

    }
    cout << cnt << "\n";
    for (int i=0; i<cnt; i++) {
        int ii=i;
        for (int j=2; j<=n; j++) {
            int si=v[j].size();
            ans[v[j][ii%si]]=1;
            ii/=si;
        }
        for (int i=1; i<=m; i++) {
            cout << ans[i];
            ans[i]=0;
        }
        cout << "\n";
    }
    return 0;
}