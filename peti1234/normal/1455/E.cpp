#include <bits/stdc++.h>

using namespace std;
long long w, x[4], xx[4], y[4], yy[4], p[4], ans, sum, o=0;
int main()
{
    cin >> w;
    while(w--) {
        ans=2e9;
        for (int i=0; i<4; i++) cin >> xx[i] >> yy[i], p[i]=i;
        do {
            for (int i=0; i<4; i++) x[i]=xx[p[i]], y[i]=yy[p[i]];
            sum=abs(x[0]-x[2])+abs(x[1]-x[3])+abs(y[0]-y[1])+abs(y[2]-y[3]);
            sum+=2*max(o, min(y[2], y[3])+min(x[0], x[2])-max(y[0], y[1])-max(x[1], x[3]));
            sum+=2*max(o, min(x[1], x[3])+min(y[0], y[1])-max(x[0], x[2])-max(y[2], y[3]));
            ans=min(ans, sum);
        } while(next_permutation(p, p+4));
        cout << ans << "\n";
    }
    return 0;
}