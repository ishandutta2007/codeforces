#include <bits/stdc++.h>

using namespace std;
int kezd, s, maxi, cnt, n, x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        if (x==0) {
            s=1;
            cnt=0;
        } else {
            if (!s) kezd++;
            cnt++;
            maxi=max(maxi, cnt);
        }
    }
    cout << max(maxi, kezd+cnt) << "\n";
    return 0;
}