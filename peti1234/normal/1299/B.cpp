#include <bits/stdc++.h>

using namespace std;
int n, x[100001], y[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n%2) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i=1; i<=n/2; i++) cin >> x[i] >> y[i];
    for (int i=1; i<=n/2; i++) {
        int a, b;
        cin >> a >> b;
        x[i]+=a, y[i]+=b;
    }
    for (int i=2; i<=n/2; i++) {
        if (x[i]!=x[i-1] || y[i]!=y[i-1]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}