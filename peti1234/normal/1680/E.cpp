#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, si, t[c][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        int kezd=n+1, veg=0;
        for (int i=0; i<2; i++) {
            for (int j=1; j<=n; j++) {
                char c;
                cin >> c;
                t[j][i]=(c=='*');
                if (t[j][i]) {
                    kezd=min(kezd, j);
                    veg=max(veg, j);
                }
            }
        }
        int a=0, b=0;
        for (int i=1; i<=n; i++) {
            if (t[i][0] && t[i][1]) {
                int s=min(a+1, b+1);
                a=s, b=s;
            }
            else {
                if (t[i][0]) {
                    b++;
                }
                if (t[i][1]) {
                    a++;
                }
            }
            a=min(a, b+1);
            b=min(b, a+1);
        }
        cout << min(a, b)+veg-kezd << "\n";

    }
    return 0;
}
/*
1
3
*.*
.*.
*/