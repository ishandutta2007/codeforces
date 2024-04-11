#include <bits/stdc++.h>

using namespace std;
const int c=2002;
long long sum;
int n, m, t[c][c], ans[c][c], p;
bool v[c][c];
queue<pair<int, int> > q;
bool jo(int a, int b) {
    return (a>0 && a<=n && b>0 && b<=m && !v[a][b]);
}
bool pr(int i, int j) {
    if (jo(i, j)) q.push({i, j}), v[i][j]=1, ans[i][j]=p+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        char c;
        cin >> c;
        t[i][j]=c-'a'+1;
    }
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        int x=t[i][j];
        if (x!=t[i-1][j] || x!=t[i][j-1] || x!=t[i+1][j]|| x!=t[i][j+1]) q.push({i, j}), ans[i][j]=1, v[i][j]=1;
    }
    while(q.size()>0) {
        int i=q.front().first, j=q.front().second;
        p=ans[i][j];
        q.pop(), sum+=p;
        pr(i-1, j), pr(i+1, j), pr(i, j-1), pr(i, j+1);
    }
    cout << sum << "\n";
    return 0;
}