#include <bits/stdc++.h>

using namespace std;
int n, m, sk, sn, ok, on;
char c[51][51];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> c[i][j];
            if (c[i][j]=='*') {
                if (!sk) sk=i;
                sn=max(sn, i);
                if (!ok || j<ok) ok=j;
                on=max(on, j);
            }
        }
    }
    for (int i=sk; i<=sn; i++) {
        for (int j=ok; j<=on; j++) {
            cout << c[i][j];
        }
        cout << "\n";
    }
    return 0;
}