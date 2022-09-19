#include <bits/stdc++.h>

using namespace std;
const int c=1000505;
int n, db[c], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        db[x]++;
    }
    for (int i=0; i<c; i++) {
        while (db[i]>1) {
            db[i+1]++, db[i]-=2;
        }
        ans+=db[i];
    }
    cout << ans << "\n";
    return 0;
}