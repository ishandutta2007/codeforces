#include <bits/stdc++.h>

using namespace std;
int n;
long long t[1001][1001], x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> t[i][j];
        }
    }
    x=__gcd(t[1][2], t[1][3]);
    long long y=t[2][3]/(t[1][2]/x)/(t[1][3]/x);
    y=sqrt(y);
    x/=y;
    cout << x << " ";
    for (int i=2; i<=n; i++) {
        cout << t[1][i]/x << " ";
    }
    return 0;
}