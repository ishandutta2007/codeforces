#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, k, t[c], db[c], x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            db[t[i]]++;
        }
        x=1, y=n;
        int pos=1, cnt=0;
        for (int i=1; i<=n; i++) {
            cnt+=db[i];
            while (2*cnt>=n+k) {
                if (i-pos<y-x) {
                    y=i, x=pos;
                }
                cnt-=db[pos];
                pos++;
            }
        }
        //cout << "valasz: ";
        cout << x << " " << y << "\n";
        int a=0, b=0, s=0;
        for (int i=1; i<=n; i++) {
            if (x<=t[i] && t[i]<=y) a++;
            else b++;
            if (a>b && (s+1<k || i==n)) {
                cout << i-a-b+1 << " " << i << "\n";
                a=0, b=0, s++;
            }
        }
        //cout << "vege\n";

        for (int i=1; i<=n; i++) {
            t[i]=0, db[i]=0;
        }
        x=0, y=0;
    }
    return 0;
}