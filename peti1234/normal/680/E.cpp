#include <bits/stdc++.h>

using namespace std;
const int c=502;
bool h[c][c], v[c][c];
int n, k, x[c][c], y[c][c], db[c][c], comp[c][c], kom[c][c], sum, ert, maxi;
vector<pair<int, int> > hat;
void add(int a, int b, int e) {
    int p=x[a][b], q=y[a][b];
    db[p][q]+=e;
    if (e==1 && db[p][q]==1) sum+=comp[p][q];
    if (e==-1 && db[p][q]==0) sum-=comp[p][q];
}
void dfs(int a, int b, int p, int q) {
    if (a<1 || a>n || b<1 || b>n || v[a][b] || !h[a][b]) return;
    v[a][b]=1, x[a][b]=p, y[a][b]=q, comp[p][q]++;
    dfs(a-1, b, p, q);
    dfs(a+1, b, p, q);
    dfs(a, b-1, p, q);
    dfs(a, b+1, p, q);
}
void sarok(int a, int b, int e) {
    add(a-1, b-1, e);
    add(a+k, b-1, e);
    add(a-1, b+k, e);
    add(a+k, b+k, e);
}
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        string s; cin >> s;
        for (int j=1; j<=n; j++) {
            if (s[j-1]=='.') h[i][j]=1;
            kom[i][j]=kom[i-1][j]+kom[i][j-1]-kom[i-1][j-1]+h[i][j];
        }
    }
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) if (!v[i][j] && h[i][j]) dfs(i, j, i, j);
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) comp[i][j]=comp[x[i][j]][y[i][j]];
    for (int i=1; i<=n-k+1; i++) {
        for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) db[i][j]=0;
        sum=0;
        for (int a=i-1; a<=i+k; a++) for (int b=0; b<=k+1; b++) add(a, b, 1);
        sarok(i, 1, -1);
        ert=kom[i+k-1][k]-kom[i-1][k]-kom[i+k-1][0]-kom[i-1][0];
        maxi=max(maxi, sum+k*k-ert);
        sarok(i, 1, 1);
        for (int j=k+1; j<=n; j++) {
            for (int f=i-1; f<=i+k; f++) {
                add(f, j-k-1, -1);
                add(f, j+1, 1);
            }
            sarok(i, j-k+1, -1);
            ert=kom[i+k-1][j]-kom[i-1][j]-kom[i+k-1][j-k]+kom[i-1][j-k];
            maxi=max(maxi, sum+k*k-ert);
            sarok(i, j-k+1, 1);
        }
    }
    cout << maxi << "\n";
    return 0;
}