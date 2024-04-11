#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, st[c], be[c], ki[c], szint[c], t[c], cnt;
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    be[a]=++cnt;
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            dfs(x);
        }
    }
    ki[a]=cnt;
}
int lsb(int a) {
    return (a & -a);
}
void add(int a, int b) {
    while (a<=n) {
        t[a]+=b;
        a+=lsb(a);
    }
}
int ask(int a) {
    int ans=0;
    while (a) {
        ans+=t[a];
        a-=lsb(a);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> st[i];
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    szint[1]=1;
    dfs(1);
    for (int i=1; i<=m; i++) {
        int id;
        cin >> id;
        if (id==1) {
            int pos, val;
            cin >> pos >> val;
            if (szint[pos]%2) {
                val*=-1;
            }
            add(be[pos], val), add(ki[pos]+1, -val);
        }
        if (id==2) {
            int pos;
            cin >> pos;
            int ert=ask(be[pos]);
            if (szint[pos]%2) {
                ert*=-1;
            }
            cout << st[pos]+ert << "\n";
        }
    }
    return 0;
}