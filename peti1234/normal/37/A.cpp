#include <bits/stdc++.h>

using namespace std;
int n, db[1005], cnt, maxi;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        db[x]++;
        if (db[x]==1) {
            cnt++;
        }
        maxi=max(maxi, db[x]);
    }
    cout << maxi << " " << cnt << "\n";
    return 0;
}