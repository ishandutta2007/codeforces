#include <bits/stdc++.h>

using namespace std;
vector<vector<bool>> sz, bal, jobb, v1, v2;
int n, m;
bool jo(int a, int b) {
    return !(a<0 || b<0 || a>=n || b>=m);
}
void bdfs(int a, int b) {
    if (!jo(a, b) || bal[a][b]) return;
    bal[a][b]=1;
    if (sz[a][b]) {
        bdfs(a-1, b-1);
        bdfs(a-1, b);
        bdfs(a-1, b+1);
        if (jo(a, b-1)) sz[a][b-1]=1;
        bdfs(a, b-1);
        bdfs(a, b+1);
        bdfs(a+1, b-1);
        if (jo(a+1, b)) sz[a+1][b]=1;
        bdfs(a+1, b);
        bdfs(a+1, b+1);
    }
}
void jdfs(int a, int b) {
    if (!jo(a, b) || jobb[a][b]) return;
    jobb[a][b]=1;
    if (sz[a][b]) {
        jdfs(a-1, b-1);
        if (jo(a-1, b)) sz[a-1][b]=1;
        jdfs(a-1, b);
        jdfs(a-1, b+1);
        jdfs(a, b-1);
        if (jo(a, b+1)) sz[a][b+1]=1;
        jdfs(a, b+1);
        jdfs(a+1, b-1);
        jdfs(a+1, b);
        jdfs(a+1, b+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    sz.resize(n), bal.resize(n), jobb.resize(n);
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        for (int j=0; j<m; j++) {
            sz[i].push_back(0), bal[i].push_back(0), jobb[i].push_back(0);
            if (s[j]=='#') sz[i][j]=1;
        }
    }
    for (int i=0; i<n; i++) {
        bdfs(i, 0);
        jdfs(i, m-1);
    }
    for (int i=0; i<m; i++) {
        jdfs(0, i);
        bdfs(n-1, i);
    }
    for (int i=0; i<n-2; i++) {
        for (int j=m-1; j>0; j--) if (bal[i][j]) bal[i+1][j]=1, bal[i][j-1]=1;
    }
    for (int i=n-1; i>0; i--) {
        for (int j=0; j<m-2; j++) if (jobb[i][j]) jobb[i-1][j]=1, jobb[i][j+1]=1;
    }
    bool sp=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (sz[i][j]+bal[i][j]+jobb[i][j]==3) {
                cout << 0 << "\n";
                return 0;
            }
            if (i+j>0 && i+j+2<n+m && bal[i][j]+jobb[i][j]==2) sp=1;
        }
    }
    if (sp) cout << 1 << "\n";
    else cout << 2  << "\n";
    return 0;
}
/*
3 3
...
...
...
*/