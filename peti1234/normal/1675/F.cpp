#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, k, s1, s2, szint[c], si[c];
vector<int> sz[c];
queue<int> q;
bool v[c], spec[c];
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k >> s1 >> s2;
        spec[s1]=1, spec[s2]=1;
        for (int i=1; i<=k; i++) {
            int x;
            cin >> x;
            spec[x]=1;
        }
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        for (int i=1; i<=n; i++) {
            si[i]=sz[i].size();
            if (!spec[i] && si[i]==1) {
                q.push(i);
            }
        }
        int db=n;
        while (q.size()>0) {
            int a=q.front();
            q.pop();
            db--;
            for (auto x:sz[a]) {
                si[x]--;
                if (si[x]==1 && !spec[x]) {
                    q.push(x);
                }
            }
        }


        dfs(s1);
        cout << 2*db-2-szint[s2] << "\n";

        for (int i=1; i<=n; i++) {
            v[i]=0, spec[i]=0, sz[i].clear();
            si[i]=0, szint[i]=0;
        }
    }
    return 0;
}