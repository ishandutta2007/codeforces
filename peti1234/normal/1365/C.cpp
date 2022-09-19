#include <bits/stdc++.h>

using namespace std;
int n, maxi, pos[200002], db[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        pos[x]=i;
    }
    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x;
        y=(pos[x]-i+n)%n;
        db[y]++, maxi=max(maxi, db[y]);
    }
    cout << maxi << "\n";
    return 0;
}