#include <bits/stdc++.h>

using namespace std;
int n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    m=n;
    while (true) {
        bool jo=1;
        for (int j=2; j<m; j++) {
            if (m%j==0) {
                m++;
                jo=0;
            }
        }
        if (jo) break;
    }
    cout << m << "\n";
    for (int i=1; i<=n; i++) {
        cout << i << " " << (i==n ? 1 : i+1) << "\n";
    }
    for (int i=1; i<=m-n; i++) {
        int s=(i%2 ? 2*i-1 : 2*i-2);
        cout << s << " " << s+2 << "\n";
    }
    return 0;
}