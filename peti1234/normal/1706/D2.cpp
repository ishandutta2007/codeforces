#include <bits/stdc++.h>

using namespace std;
const int c=100005, gy=350;
int w, n, k, maxi[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        int mini=c, x, ans=c;
        for (int i=0; i<c; i++) {
            maxi[i]=i;
        }
        for (int i=1; i<=n; i++) {
            cin >> x;
            mini=min(mini, x);
            int ut=x/k;
            //cout << "kezd " << ut << "\n";
            maxi[1]=max(maxi[1], ut);
            for (int i=ut+1; i<=gy; i++) {
                int y=x/i;
                if (y && x/y==i) {
                    //cout << "fontos " << i << "\n";
                    maxi[ut+1]=max(maxi[ut+1], i);
                    ut=i;
                }
            }
            for (int i=min(k, gy); i>=1; i--) {
                int ert=x/i;
                if (ert>ut) {
                    maxi[ut+1]=max(maxi[ut+1], ert);
                    ut=ert;
                }
            }
            // x/1, x/2, ... x/k
        }
        for (int i=1; i<=mini; i++) {
            maxi[i]=max(maxi[i], maxi[i-1]);
            ans=min(ans, maxi[i]-i);
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
1
2 2
1 3
*/