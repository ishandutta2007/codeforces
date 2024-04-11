#include <bits/stdc++.h>

using namespace std;
int db[28];
int t[1001][1001];
int n, m, k, p, e, v;
void ki(int a, int b)
{
    while(!db[e]) {
        e++;
    }
    t[a][b]=e;
    db[e]--;
}
void na(int a, int b)
{
    while(!db[v]) {
        v--;
    }
    t[a][b]=v;
    db[v]--;
}
int main()
{
    cin >> n >> m >> k;
    for (int i=1; i<=n*m; i++) {
        char c;
        cin >> c;
        int x=c-'a'+1;
        db[x]++;
    }
    p=1;
    e=1, v=27;
    for (int i=1; i<=m; i++) {
        for (int j=p; j<=k; j++) {
            ki(j, i);
        }
        for (int j=n; j>=k+1; j--) {
            na(j, i);
        }
        for (int j=p-1; j>=1; j--) {
            na(j, i);
        }
        while(t[p][i]!=t[k][i]) {
            p++;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c='a'+t[i][j]-1;
            cout << c;
        }
        cout << "\n";
    }
    return 0;
}