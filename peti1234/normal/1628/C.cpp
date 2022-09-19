#include <bits/stdc++.h>

using namespace std;
int w, n, t[1005][1005], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin >> t[i][j];
        for (int kezd=1; kezd<=n/2; kezd+=2) {
            int a=kezd, b=kezd;
            int veg=n+1-kezd;
            //cout << a << " " << b << " " << kezd << " " << veg << "\n";
            for (int i=0; i<4*(veg-kezd); i++) {
                if (i%4<2) {
                    //cout << "fontos " << a << " " << b << "\n";
                    ans^=t[a][b];
                }
                int s=i/(veg-kezd);
                if (s==0) a++;
                if (s==1) b++;
                if (s==2) a--;
                if (s==3) b--;
            }
        }
        cout << ans << "\n";
        ans=0;
    }
    return 0;
}
/*
1
2
0 0
0 0
*/