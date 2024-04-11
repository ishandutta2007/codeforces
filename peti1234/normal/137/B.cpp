#include <bits/stdc++.h>

using namespace std;
int n, db[5005], cnt;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        db[x]++;
        if (x>n || db[x]>1) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}