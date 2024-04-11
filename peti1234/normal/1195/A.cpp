#include <bits/stdc++.h>

using namespace std;
int n, k, db[1005], cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        db[x]++;
    }
    for (int i=1; i<=k; i++) {
        if (db[i]%2) {
            cnt++;
        }
    }
    cout << n-cnt/2 << "\n";
    return 0;
}