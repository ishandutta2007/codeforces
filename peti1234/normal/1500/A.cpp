#include <bits/stdc++.h>

using namespace std;
const int c=5000002;
int n, t[c], ki[c][2];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int x=t[i]+t[j];
            int a=ki[x][0], b=ki[x][1];
            if (a && i!=a && i!=b && j!=b) {
                cout << "YES\n";
                cout << a << " " << b << " " << i << " " << j << "\n";
                return 0;
            }
            ki[x][0]=i, ki[x][1]=j;
        }
    }
    cout << "NO\n";
    return 0;
}