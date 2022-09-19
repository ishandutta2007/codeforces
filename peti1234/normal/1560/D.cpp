#include <bits/stdc++.h>

using namespace std;
const int c=61;
long long w, n, m, po[c], th[c];
long long si(long long a) {
    int db=0;
    while (a) {
        a/=10;
        db++;
    }
    return db;
}
int main()
{
    ios_base::sync_with_stdio(false);
    po[0]=1, th[0]=1;
    for (int i=1; i<=18; i++) {
        th[i]=th[i-1]*10;
    }
    for (int i=1; i<c; i++) {
        po[i]=po[i-1]*2;
    }
    cin >> w;
    while (w--) {
        cin >> n;
        int mini=10;
        for (int s=0; s<c; s++) {
            m=po[s];
            int x=si(n), y=si(m);
            int pos=y-1;
            for (int i=x-1; i>=0; i--) {
                if (pos>=0 && n/th[i]%10==m/th[pos]%10) {
                    pos--;
                }
            }
            mini=min(mini, x+y-2*(y-1-pos));
        }
        cout << mini << "\n";
    }
    return 0;
}