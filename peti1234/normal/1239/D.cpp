#include <bits/stdc++.h>

using namespace std;
vector<int> sz[1000001];
vector<int> inv[1000001];
int q, n, m;
bool v[1000001];
int cnt()
{
    int db=0;
    for (int i=1; i<=n; i++) {
        db+=v[i];
    }
    return db;
}
void sol()
{
    int a=cnt();
    cout << "Yes" << "\n";
    cout << a << " " << n-a << "\n";
    for (int i=1; i<=n; i++) {
        if (v[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
}
void invsol()
{
    for (int i=1; i<=n; i++) {
        v[i]=!v[i];
    }
    sol();
}
void dfs(int a)
{
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            dfs(x);
        }
    }
}
void invdfs(int a)
{
    v[a]=true;
    for (int i=0; i<inv[a].size(); i++) {
        int x=inv[a][i];
        if (!v[x]) {
            invdfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            sz[i].clear();
            inv[i].clear();
            v[i]=false;
        }
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            if (a!=b) {
                sz[a].push_back(b);
                inv[b].push_back(a);
            }
        }
        bool c=false;
        dfs(1);
        int x=cnt();
        if (x>0 && x<n) {
            sol();
            c=true;
        }
        for (int i=1; i<=n; i++) {
            v[i]=false;
        }
        invdfs(1);
        x=cnt();
        if (!c && x>0 && x<n) {
            invsol();
            c=true;
        }
        if (!c) {
            cout << "No" << "\n";
        }

    }
    return 0;
}