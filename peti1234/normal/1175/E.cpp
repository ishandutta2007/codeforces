#include <bits/stdc++.h>
 
using namespace std;
int t[500002];
int er[500002][21];
int n, m;
int solve(int a, int b, int c)
{
    if (er[a][20]<b) {
        return -1;
    }
    if (a==b) {
        return 0;
    }
    if (er[a][0]>=b) {
        return 1;
    }
    for (int j=c; j>=0; j--) {
        if (er[a][j]<b) {
            a=er[a][j];
            return solve(a, b, j-1)+(1<<j);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        t[a]=max(t[a], b);
    }
    for (int i=0; i<=500000; i++) {
        t[i]=max(i, t[i]);
        t[i]=max(t[i], t[i-1]);
        er[i][0]=t[i];
    }
    for (int j=1; j<=20; j++) {
        for (int i=0; i<=500000; i++) {
            int a=er[i][j-1];
            er[i][j]=er[a][j-1];
        }
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b, 20) << "\n";
    }
    return 0;
}