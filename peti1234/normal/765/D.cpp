#include <bits/stdc++.h>

using namespace std;
int n, db, f[100002], fp[100002];
bool c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> f[i];
    for (int i=1; i<=n; i++) {
        if (f[i]!=f[f[i]]) c=true;
        if (f[i]==i) db++, fp[i]=db;
    }
    for (int i=1; i<=n; i++) fp[i]=fp[f[i]];
    if (c) cout << -1 << "\n";
    else {
        cout << db << "\n";
        for (int i=1; i<=n; i++) cout << fp[i] << " ";
        cout << "\n";
        for (int i=1; i<=n; i++) if (f[i]==i) cout << i << " ";
        cout << "\n";
    }
    return 0;
}