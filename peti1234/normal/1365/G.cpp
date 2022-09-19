#include <bits/stdc++.h>

using namespace std;
const int c=1002, k=14;
long long ans[c], n, x=1, db, maxi, s[k], f[k], p=1;
bool v[c][k];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<(1<<k); i++) if (__builtin_popcount(i)==6 && db<n) {
        db++; int x=i;
        for (int j=1; j<=13; j++) v[db][j]=x%2, x/=2, s[j]+=v[db][j];
    }
    for (int j=1; j<k; j++) if (s[j]) {
        cout << "? " << s[j] << " ";
        for (int i=1; i<=n; i++) if (v[i][j]) cout << i << " ";
        cout.flush() << "\n";
        cin >> f[j];
    }
    for (int i=1; i<=n; i++) for (int j=1; j<k; j++) if (!v[i][j]) ans[i]=(ans[i]|f[j]);
    cout << "! ";
    for (int i=1; i<=n; i++) cout << ans[i] << " ";
    return 0;
}