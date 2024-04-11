#include <bits/stdc++.h>

using namespace std;
const int c=400005;
int n, m, ki[c], id[c], l[c], r[c], dir[c], sor[c], cnt;;
vector<int> sz[c];
bool v[c];
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        if (a>b) {
            swap(a, b);
        }
        ki[b]=a;
    }
}
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
    sor[a]=++cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> id[i] >> l[i] >> r[i];
        unio(l[i], r[i]+n), unio(l[i]+n, r[i]);
    }
    for (int i=1; i<=n; i++) {
        int a=holvan(i), b=holvan(i+n);
        if (a==b) {
            cout << "NO\n";
            return 0;
        }
        dir[i]=(a<b ? 1 : 2);
        //cout << "fontos " << i << " " << dir[i] << "\n";
    }
    for (int i=1; i<=m; i++) {
        int t=id[i], a=l[i], b=r[i];
        if (dir[a]==t) sz[b].push_back(a);
        else sz[a].push_back(b);
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            dfs(i);
        }
    }
    for (int i=1; i<=n; i++) {
        for (auto x:sz[i]) {
            if (sor[x]>sor[i]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (int i=1; i<=n; i++) {
        cout << (dir[i]==1 ? "L" : "R") << " " << sor[i] << "\n";
    }
    return 0;
}
/*
4 4
1 1 2
1 2 3
2 3 4
2 4 1
*/