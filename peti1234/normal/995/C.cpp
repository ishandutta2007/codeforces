#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long x[c], y[c], n, ans[c], k=1500000;
long long jo(long long a, long long b) {
    return a*a+b*b<=k*k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    while (true) {
        long long aa=0, bb=0;
        for (int i=1; i<=n; i++) {
             bool p=jo(aa+x[i], bb+y[i]), q=jo(aa-x[i], bb-y[i]);
             bool lep=0;
             int f=rand()%2;
             if ((q || !p) && ((q && !p) || f)) {
                lep=1;
             }
             if (!lep) {
                ans[i]=1;
                aa+=x[i], bb+=y[i];
             } else {
                ans[i]=-1;
                aa-=x[i], bb-=y[i];
             }
        }
        if (jo(aa, bb)) {
            for (int i=1; i<=n; i++) {
                cout << ans[i] << " ";
            }
            cout << "\n";
            return 0;
        }
    }
    return 0;
}