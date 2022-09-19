#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, m, a[c], b[c], f[c], e[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m, e[0]=m;
    cout << 0 << " ";
    for (int i=1; i<n; i++) cin >> a[i];
    for (int i=1; i<n; i++) {
        cin >> b[i];
        f[i]=min(f[i-1], e[i-1])+a[i];
        e[i]=min(f[i-1]+m, e[i-1])+b[i];
        cout << min(f[i], e[i]) << " ";
    }
    cout << "\n";
    return 0;
}