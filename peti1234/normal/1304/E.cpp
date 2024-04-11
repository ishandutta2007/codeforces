#include <bits/stdc++.h>

using namespace std;
const int c=100002, k=20;
int n, q, szint[c], fel[c][k];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    for (int i=1; i<k; i++) {
        fel[a][i]=fel[fel[a][i-1]][i-1];
    }
    for (int x:sz[a]) {
        if (!v[x]) {
            fel[x][0]=a;
            szint[x]=szint[a]+1;
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
int tav(int a, int b) {
    return szint[a]+szint[b]-2*szint[lca(a, b)];
}
void calc(int x, int y, int &cs, int &sum) {
    int koz=lca(x, y), bal=lca(cs, x), jobb=lca(cs, y);
    if (szint[bal]>szint[koz]) {
        sum-=tav(cs, bal);
        cs=bal;
    } else if (szint[jobb]>szint[koz]) {
        sum-=tav(cs, jobb);
        cs=jobb;
    } else {
        sum-=tav(cs, koz);
        cs=koz;
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
    szint[1]=1;
    dfs(1);
    cin >> q;
    for (int i=1; i<=q; i++) {
        int x, y, sum, cs1, cs2;
        cin >> x >> y >> cs1 >> cs2 >> sum;
        int s=tav(cs1, cs2);
        if (s<=sum && (sum-s)%2==0) {
            cout << "YES\n";
            continue;
        }
        int kor=tav(x, y)+1;
        calc(x, y, cs1, sum);
        calc(x, y, cs2, sum);
        int kis=tav(cs1, cs2), nagy=kor-kis;
        if (sum>=0 && (sum-kis>=0 && (sum-kis)%2==0) || (sum-nagy>=0 && (sum-nagy)%2==0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
/*
14
4 9
3 7
4 1
3 2
14 9
7 6
10 13
8 7
5 7
7 10
1 3
12 3
7 11
1
13 6 14 9 3
*/