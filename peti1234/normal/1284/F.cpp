#include <bits/stdc++.h>

using namespace std;
const int c=250002, k=20;
int n, f[c], szint[c], fel[c][k], kov[c], si[c];
vector<int> sz[c], s[c];
bool v[c], cl[c];
queue<int> q;
void dfs(int a) {
    fel[a][0]=f[a], kov[a]=a;
    v[a]=true;
    for (int i=1; i<k; i++) {
        fel[a][i]=fel[fel[a][i-1]][i-1];
    }
    for (int x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            f[x]=a;
            dfs(x);
        }
    }
}
int lca(int a, int b) {
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) {
            a=fel[a][i];
        }
    }
    for (int i=k-1; i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            a=fel[a][i], b=fel[b][i];
        }
    }
    if (a!=b) {
        a=fel[a][0];
    }
    return a;
}
int holvan(int a) {
    if (kov[a]==a) {
        return a;
    }
    int x=holvan(kov[a]);
    kov[a]=x;
    return x;
}
int solve(int a, int x, int b) {
    int s=holvan(a);
    if (szint[s]>szint[x]) {
        return s;
    }
    for (int i=k-1; i>=0; i--) {
        int s=holvan(fel[b][i]);
        if (szint[s]>szint[x]) {
            b=s;
        }
    }
    return b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        s[a].push_back(b), s[b].push_back(a);
    }
    szint[1]=1;
    dfs(1);
    for (int i=1; i<=n; i++) {
        si[i]=s[i].size();
        if (si[i]==1) {
            q.push(i);
        }
    }
    cout << n-1 << "\n";
    for (int i=1; i<n; i++) {
        int x=q.front(), y, e;
        q.pop();
        cl[x]=1;
        for (int i:s[x]) {
            if (!cl[i]) {
                y=i;
                si[i]--;
                if (si[i]==1) {
                    q.push(i);
                }
            }
        }
        e=solve(x, lca(x, y), y);
        kov[e]=f[e];
        cout << e << " " << f[e] << " " << x << " " << y << "\n";
    }
    return 0;
}