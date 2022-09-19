#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int t[c], db[c], n, jo=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=1; i<=n/3; i++) if (n%i==0) {
        for (int j=0; j<i; j++) db[j]=0;
        for (int j=1; j<=n; j++) db[j%i]+=t[j];
        for (int j=0; j<i; j++) if (db[j]==n/i) jo=1;
    }
    if (jo) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}