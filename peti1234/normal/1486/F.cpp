#include <bits/stdc++.h>

using namespace std;
const int c=300002, k=20;
int n, m, szint[c], fel[c][k];
vector<int> sz[c];
bool v[c];
long long koz[c], kom[c], gy[c], ans;
map<pair<int, int>, int> cs;
void dfs(int a) {
    v[a]=true;
    for (int i=1; i<k; i++) {
        fel[a][i]=fel[fel[a][i-1]][i-1];
    }
    for (int x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a;
            dfs(x);
        }
    }
}
void kozadd(int a) {
    ans+=koz[a];
    koz[a]++;
}
void utadd(int a, int b) {
    kom[a]++, kom[b]--;
}
void gyadd(int a) {
    ans-=gy[a];
    gy[a]++;
}
void csadd(int a, int b) {
    if (a>b) {
        swap(a, b);
    }
    ans+=cs[{a, b}];
    cs[{a, b}]++;
}
void lca(int a, int b) {
    if (a==b) {
        kozadd(a);
        return;
    }
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    int aa=a, bb=b;
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>szint[b]) {
            a=fel[a][i];
        }
    }
    if (fel[a][0]==b) {
        utadd(aa, b);
        kozadd(b);
        gyadd(a);
        return;
    }
    if (szint[a]>szint[b]) {
        a=fel[a][0];
    }
    for (int i=k-1; i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            a=fel[a][i], b=fel[b][i];
        }
    }
    csadd(a, b);
    gyadd(a), gyadd(b);
    a=fel[a][0];
    kozadd(a);
    utadd(aa, a), utadd(bb, a);
}
void dfs2(int a) {
    for (int x:sz[a]) {
        if (fel[x][0]==a) {
            dfs2(x);
            kom[a]+=kom[x];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    szint[1]=1;
    dfs(1);
    cin >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        lca(a, b);
    }
    dfs2(1);
    for (int i=1; i<=n; i++) {
        ans+=koz[i]*kom[i];
        ans-=gy[i]*(kom[i]-gy[i]);
    }
    cout << ans << "\n";
    return 0;
}