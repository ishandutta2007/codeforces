#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int n, k, xx=1, yy, cnt, kezd=1, t[c], db[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int veg=1; veg<=n; veg++) {
        db[t[veg]]++;
        if (db[t[veg]]==1) cnt++;
        while (cnt>k) {
            db[t[kezd]]--;
            if (db[t[kezd]]==0) cnt--;
            kezd++;
        }
        if (veg-kezd>yy-xx) yy=veg, xx=kezd;
    }
    cout << xx << " " << yy << "\n";
    return 0;
}