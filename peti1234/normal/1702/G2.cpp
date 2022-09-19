#include <bits/stdc++.h>

using namespace std;

/*
binary lifting
szint[1]=1 kell, c es k erteke valtozhat
1:45 alatt irtam le :)
*/


const int c=200005, k=20;
int n, q, szint[c], fel[c][k];
vector<int> sz[c];
bool v[c];

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




int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    szint[1]=1;
    dfs(1);

    cin >> q;
    while (q--) {
        int s, bal=0, jobb=0, fel=0;
        cin >> s;
        bool baj=0;
        for (int i=1; i<=s; i++) {
            int x;
            cin >> x;
            if (fel==0 || szint[x]<szint[fel]) fel=x;
            //cout << "fontos " << x << " " << bal << " " << jobb << "\n";
            if (i==1) bal=x;
            else {
                int k=lca(bal, x);
                if (k==bal || k==x) {
                    if (szint[x]>szint[bal]) bal=x;
                } else {
                    if (jobb) {
                        int k=lca(x, jobb);
                        if (k!=x && k!=jobb) baj=1;
                    }
                    if (!jobb || szint[x]>szint[jobb]) jobb=x;
                }
            }
        }
        if (bal && jobb && szint[lca(bal, jobb)]>szint[fel]) baj=1;
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}
/*
5
1 2
2 3
2 4
4 5
1
5
1 2 3 4 5
*/