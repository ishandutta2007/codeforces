#include <bits/stdc++.h>

using namespace std;
const int c=35000000;
int t[c], db[c], kom[c], maxi;
long long sum, n, po=1, h, cnt;
long long rs(int a, int b) {
    if (a==0) return kom[b];
    else return kom[b]-kom[a-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        maxi=max(maxi, t[i]);
    }
    while(po<=2*maxi) {
        cnt=0;
        h=2*po;
        for (int i=0; i<h; i++) db[i]=0, kom[i]=0;
        for (int i=1; i<=n; i++) {
            db[t[i]%h]++;
        }
        kom[0]=db[0];
        for (int i=1; i<h; i++) kom[i]=kom[i-1]+db[i];
        if (po==1) {
            cnt=db[0]*db[1];
        }
        else {
            for (int i=0; i<h; i++) {
                long long g=db[i];
                if (i<po/2) {
                    cnt+=g*rs(0, i-1)+g*(g-1)/2;
                } else if (i<po) {
                    cnt+=g*rs(0, po-1-i);
                } else if (i<po*3/2) {
                    cnt+=g*rs(h-i, i-1)+g*(g-1)/2;
                } else {
                    cnt+=g*rs(h-i, 3*po-1-i);
                }
            }
            cnt=n*(n-1)/2-cnt;
        }
        if (cnt%2) sum+=po;
        po=h;
    }
    cout << sum << "\n";
    return 0;
}
/*
2
1 3
*/