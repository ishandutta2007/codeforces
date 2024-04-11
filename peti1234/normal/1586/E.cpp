#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int n, m, q, fel[c], szint[c], db[c], l[c], r[c], cnt;
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x]=a;
            dfs(x);
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
    szint[1]=1;
    dfs(1);
    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> l[i] >> r[i];
        db[l[i]]++, db[r[i]]++;
    }
    for (int i=1; i<=n; i++) {
        if (db[i]%2) {
            cnt++;
        }
    }
    if (cnt) {
        cout << "NO\n";
        cout << cnt/2 << "\n";
        return 0;
    }
    cout << "YES\n";
    for (int i=1; i<=q; i++) {
        vector<int> bal, jobb;
        int x=l[i], y=r[i];
        while (x!=y) {
            if (szint[x]>szint[y]) {
                bal.push_back(x);
                x=fel[x];
            } else {
                jobb.push_back(y);
                y=fel[y];
            }
        }
        int s=bal.size()+jobb.size()+1;
        reverse(jobb.begin(), jobb.end());
        cout << s << " ";
        for (auto cs:bal) {
            cout << cs << " ";
        }
        cout << x << " ";
        for (auto cs:jobb) {
            cout << cs << " ";
        }
        cout << "\n";
    }
    return 0;
}