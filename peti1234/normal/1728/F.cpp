#include <bits/stdc++.h>

using namespace std;
const int c=2005;
int n, t[c], par[c], ut, cnt;
long long sum;
vector<int> sz[c];
priority_queue<pair<int, int> > q;
bool v[c];
bool dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            v[x]=1;
            if (!par[x] || dfs(par[x])) {
                par[a]=x, par[x]=a;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        q.push({-t[i], i});
    }
    while (cnt<n) {
        int s=n+cnt+1, id=q.top().second, ert=-q.top().first;
        q.pop();
        if (ut>=ert) {
            q.push({-ert-t[id], id});
        } else {
            for (int i=1; i<=n; i++) {
                if (ert%t[i]==0) {
                    sz[s].push_back(i);
                }
            }
            if (dfs(s)) {
                cnt++;
                ut=ert, sum+=ert;
                q.push({-ert-t[id], id});
            } else {
                sz[s].clear();
            }
            for (int i=1; i<=2*n; i++) {
                v[i]=0;
            }
        }
    }
    cout << sum << "\n";
    return 0;
}
/*
2
1 1
*/