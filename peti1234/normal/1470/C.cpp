#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long regi[c], uj[c], n, k, db, pos, cnt, lb, hb;
int kerd(int a) {
    cout.flush() << "? " << a+1 << "\n";
    cnt++;
    int x; cin >> x;
    return x;
}
void valt() {
    for (int i=0; i<n; i++) {
        uj[(i+1)%n]+=regi[i]-regi[i]/2;
        uj[(i-1+n)%n]+=regi[i]/2;
    }
    for (int i=0; i<n; i++) {
        regi[i]=uj[i], uj[i]=0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        regi[i]=k;
    }
    while(true) {
        int x=kerd(pos);
        if (x!=regi[pos]) {
            if (x>regi[pos]) {
                hb=pos, lb=pos-2*cnt;
            } else {
                lb=pos, hb=pos+2*cnt;
            }
            valt();
            break;
        }
        valt();
        pos+=cnt, pos%=n;
    }
    while(hb-lb>2) {
        int mid=rand()%(hb-lb+1)+lb+1, v=(mid+10*n)%n;
        int x=kerd(v);
        if (x>regi[v]) {
            hb=mid;
        }
        if (x<regi[v]) {
            lb=mid;
        }
        valt();
    }
    int ans=(lb+1+10*n)%n+1;
    cout.flush() << "! " << ans << "\n";
    return 0;
}