#include <bits/stdc++.h>

using namespace std;
const int c=100005, k=20;
int n, q, szint[c], ert[c], cnt, be[c], ki[c], fel[c][k];
vector<int> sz[c];
bool v[c];
long long t[c];

void dfs(int a) {
    v[a]=true;
    be[a]=++cnt;
    for (int i=1; i<k; i++) {
        fel[a][i]=fel[fel[a][i-1]][i-1];
    }
    for (auto x:sz[a]) {
        if (!v[x]) {
            fel[x][0]=a;
            szint[x]=szint[a]+1;
            dfs(x);
        }
    }
    ki[a]=cnt;
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
    if (a==b) {
        return a;
    }
    return fel[a][0];
}

int lsb(int a) {
    return (a & -a);
}
void add(int a, int b) {
    while (a<=n+1) {
        t[a]+=b;
        a+=lsb(a);
    }
}
long long ask(int a) {
    long long ans=0;
    while (a) {
        ans+=t[a];
        a-=lsb(a);
    }
    return ans;
}
int main()
{
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> ert[i];
        ert[i]=abs(ert[i]);
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    szint[1]=1;
    dfs(1);

    for (int i=1; i<=n; i++) {
        add(be[i]+1, ert[i]);
        add(ki[i]+1, -ert[i]);
    }
    for (int i=1; i<=q; i++) {
        int p, x, y;
        cin >> p >> x >> y;
        if (p==1) {
            y=abs(y);
            int dif=y-ert[x];
            add(be[x]+1, dif);
            add(ki[x]+1, -dif);
            ert[x]=y;
        } else {
            int s=lca(x, y);
            cout << 2*(ask(be[x])+ask(be[y])-2*ask(be[s]))+ert[x]+ert[y]-2*ert[s] << "\n";
        }
    }
    return 0;
}
/*
6 1
10 -9 2 -1 4 -6
1 5
5 4
5 6
6 2
6 3
2 1 2
*/