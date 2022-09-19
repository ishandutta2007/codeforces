#include <bits/stdc++.h>

using namespace std;


const int c=200005, k=20;
int n, m, szint[c], fel[c][k];
int bal[c], jobb[c], ki[c], ert[c];
vector<int> sz[c];
bool v[c], v2[c];

void dfs(int a) {
    v[a]=true;
    for (int i=1; i<k; i++) {
        fel[a][i]=(fel[fel[a][i-1]][i-1]);
    }
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a;
            dfs(x);
        }
    }
}
int lca(int a, int b) {
    if (szint[a]<szint[b]) swap(a, b);
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) a=fel[a][i];
    }
    for (int i=k-1; i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            a=fel[a][i], b=fel[b][i];
        }
    }
    if (a==b) return a;
    return fel[a][0];
}
int tav(int a, int b) {
    return szint[a]+szint[b]-2*szint[lca(a, b)];
}

int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
bool unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
        return true;
    }
    return false;
}
void dfs2(int a) {
    v2[a]=true;
    for (auto x:sz[a]) {
        if (!v2[x]) {
            ert[x]+=ert[a];
            dfs2(x);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        bal[i]=a, jobb[i]=b;
        if (unio(a, b)) {
            sz[a].push_back(b), sz[b].push_back(a);
        }
    }

    szint[1]=1;
    dfs(1);

    for (int i=1; i<=m; i++) {
        int a=bal[i], b=jobb[i];
        if (szint[a]<szint[b]) {
            swap(a, b);
        }
        int koz=lca(a, b);
        ert[a]++;
        if (koz!=b) {
            ert[b]++;
        } else {
            int sa=a;
            for (int i=k-1; i>=0; i--) {
                if (szint[fel[sa][i]]>szint[b]) {
                    sa=fel[sa][i];
                }
            }
            //cout << "fontos " << a << " " << b << " " << koz << " " << sa << "\n";
            ert[1]++;
            ert[sa]--;
        }
    }

    dfs2(1);

    for (int i=1; i<=n; i++) {
        cout << (ert[i]==m);
    }
    cout << "\n";

    return 0;
}
/*
10 15
1 2 2 3 3 4 3 5 2 6 6 7 1 8 8 9 9 10
2 8
1 4 7 1 10 8 5 2 4 2















*/