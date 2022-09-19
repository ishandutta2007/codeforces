#include <bits/stdc++.h>

using namespace std;
const int c=300005, k=20;
int w, n, szint[c], fel[c][k], ans[c], d;
vector<int> sz[c], l[c];
bool v[c];

void dfs(int a) {
    v[a]=true;
    d=max(szint[a], d);
    for (int i=1; i<k; i++) {
        fel[a][i]=fel[fel[a][i-1]][i-1];
    }
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a;
            dfs(x);
        }
    }
    l[szint[a]].push_back(a);
}

int lca(int a, int b) {
    if (a==0) {
        return b;
    }
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) {
            a=fel[a][i];
        }
    }
    if (a==b) {
        return a;
    }
    for (int i=k-1; i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            a=fel[a][i], b=fel[b][i];
        }
    }
    return fel[a][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        szint[1]=1;
        dfs(1);
        ans[n]=d-1;
        int cs=0, kis=0, nagy=1e9;
        for (int i=d; i>=3; i--) {
            for (auto x:l[i]) {
                cs=lca(cs, x);
            }
            kis=d-i+2, nagy=min(nagy-1, 2*szint[cs]-2);
            //cout << "fontos " << i << " " << szint[cs] << " " << kis << " " << nagy << "\n";
            if (kis+2<=nagy) {
                ans[(nagy-kis)/2]=i-2;
            }
        }
        for (int i=n-1; i>=1; i--) {
            if (!ans[i]) {
                ans[i]=ans[i+1];
            }
        }

        //cout << "valasz.............. ";
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";


        for (int i=0; i<=n+3; i++) {
            v[i]=0, ans[i]=0, szint[i]=0, sz[i].clear(), l[i].clear();
            for (int j=0; j<k; j++) fel[i][j]=0;
        }
        d=0;

    }
    return 0;
}
/*
1
7
1 2
1 3
3 4
3 5
3 6
5 7
*/