#include <bits/stdc++.h>

using namespace std;
int n, x, y, maxi, cnt, z;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n==1) {
        cout << 1 << "\n";
        return 0;
    }
    cin >> x >> y;
    maxi=2, cnt=2;
    for (int i=3; i<=n; i++) {
        cin >> z;
        if (x+y==z) {
            cnt++;
        } else {
            cnt=2;
        }
        maxi=max(maxi, cnt);
        x=y, y=z;
    }
    cout << maxi << "\n";
    return 0;
}