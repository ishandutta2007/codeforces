#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, cnt, sum, ans[c], si[c], db1[c], ert1[c], db2[c], ert2[c];
vector<int> sz[c];
bool v[c], v2[c];
bool kell(int x) {
    return (db2[x]>db1[x] || db2[x]==db1[x] && ert2[x]<ert1[x]);
}
void dfs(int a) {
    v[a]=true;
    db2[a]=1, ert2[a]=si[a];
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            db2[a]+=db1[x];
            ert2[a]+=ert1[x];
            if (kell(x)) {
                db1[a]+=db2[x];
                ert1[a]+=ert2[x];
            } else {
                db1[a]+=db1[x];
                ert1[a]+=ert1[x];
            }
        }
    }
}
void dfs2(int a, bool b) {
    if (b) {
        cnt++;
        ans[a]=si[a];
    } else {
        ans[a]=1;
    }
    sum+=ans[a];

    v2[a]=true;
    for (auto x:sz[a]) {
        if (!v2[x]) {
            if (!b && kell(x)) {
                dfs2(x, 1);
            } else {
                dfs2(x, 0);
            }
        }
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
        cout << 2 << " " << 2 << "\n";
        cout << 1 << " " << 1 << "\n";
        return 0;
    }
    for (int i=1; i<=n; i++) {
        si[i]=sz[i].size();
    }
    dfs(1);

    dfs2(1, kell(1));



    cout << cnt << " " << sum << "\n";
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
/*
8
1 2 2 3 3 4 4 5 3 6 6 7 7 8
*/