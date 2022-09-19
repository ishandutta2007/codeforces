#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int n, m, s[c], o[c], t[c][c];
long long sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c; cin >> c;
            if (c=='*') {
                s[i]++, o[j]++, t[i][j]=1;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (t[i][j]) {
                sum+=(s[i]-1)*(o[j]-1);
            }
        }
    }
    cout << sum << "\n";
    return 0;
}