#include <bits/stdc++.h>

using namespace std;
bool v[102][102];
int n, m, a, b, p=1;
void l(int x, int y) {
    cout << x << " " << y << "\n";
    a=x, b=y, v[x][y]=1;
}
void pr(int x, int y) {
    if (!v[x][y]) l(x, y);
}
int main()
{
    cin >> n >> m >> a >> b;
    l(a, b), l(1, b);
    for (int i=1; i<=n; i++) {
        pr(i, p);
        for (int j=2; j<m; j++) pr(i, j);
        if (!v[i][m]) pr(i, 1), pr(i, m), p=m;
        else pr(i, 1), p=1;
    }
    return 0;
}