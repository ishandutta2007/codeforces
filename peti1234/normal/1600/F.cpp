#include <bits/stdc++.h>

using namespace std;
const int cc=43;
int n, m;
bool v[51][51];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    n=min(n, cc);
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        if (a<=n && b<=n) {
            v[a][b]=v[b][a]=1;
        }
    }
    for (int a=1; a<=n; a++) {
        for (int b=a+1; b<=n; b++) {
            for (int c=b+1; c<=n; c++) {
                for (int d=c+1; d<=n; d++) {
                    for (int e=d+1; e<=n; e++) {
                        int sum=v[a][b]+v[b][c]+v[c][d]+v[d][e]+v[e][a]+v[a][c]+v[c][e]+v[e][b]+v[b][d]+v[d][a];
                        if (sum==0 || sum==10) {
                            cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}