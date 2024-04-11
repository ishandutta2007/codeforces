#include <bits/stdc++.h>

using namespace std;
int n, l, r, x, c[15], mini, maxi, sum, db;
int main()
{
    // 1100 (2) 12
    // 1010 (2) 10
    // (10&12) 1000 (2)=8 (10)


    // 0101010110110100011010
    // 0000000000000001000000
    // 0000000000000000000000
    cin >> n >> l >> r >> x;
    for (int i=0; i<n; i++) {
        cin >> c[i];
    }
    for (int i=0; i<(1<<n); i++) {
        sum=0, maxi=0, mini=1e9;
        for (int j=0; j<n; j++) {
            // a j. rtke 1<<j;
            // 1, 2, 4, 8 ....
            // a j. elem pontosan akkor van benne, ha i&(1<<j) nem 0
            if ((i&(1<<j))!=0) {
                // j. elem benne van
                sum+=c[j];
                maxi=max(maxi, c[j]);
                mini=min(mini, c[j]);
            }
        }
        if (l<=sum && sum<=r && maxi-mini>=x) {
            db++;
        }
    }
    cout << db << "\n";
    return 0;
}