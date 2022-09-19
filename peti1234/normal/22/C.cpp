#include <bits/stdc++.h>

using namespace std;
long long n, m, x;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> x;
    if (m<n-1 || m>(n-1)*(n-2)/2+1) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i=1; i<=n; i++) {
        if (i!=x) {
            cout << i << " " << x << "\n";
        }
    }
    m-=n-1;
    if (x==n) {
        n--;
    }
    for (int i=1; i<n; i++) {
        if (!m) {
            break;
        }
        for (int j=i+1; j<n; j++) {
            if (m && i!=j && i!=x && j!=x) {
                cout << i << " " << j << "\n";
                m--;
            }
        }
    }
    return 0;
}