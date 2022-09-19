#include <bits/stdc++.h>

using namespace std;
int w, n, a, b;
int kerd(int a, int b, int c) {
    cout.flush() << "? " << a << " " << b << " " << c << endl;
    int x;
    cin >> x;
    return x;
}
void solve(int c, int d) {
    int aa=kerd(b, c, d), bb=kerd(a, c, d), cc=kerd(a, b, d), dd=kerd(a, b, c), ert=max({aa, bb, cc, dd});
    if (aa==ert) {
        if (bb==ert) a=c, b=d;
        else if (cc==ert) a=d;
        else a=c;
    } else {
        if (bb==ert) {
            if (cc==ert) b=d;
            else b=c;
        }
    }
    //cout.flush() << "vege " << a << " " << b << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        a=1, b=2;
        for (int i=3; i<n; i+=2) {
            solve(i, i+1);
        }
        if (n%2) {
            if (a!=1 && b!=1) solve(1, n);
            else if (a!=2 && b!=2) solve(2, n);
            else solve(3, n);
        }
        cout.flush() << "! " << a << " " << b << endl;
    }
    return 0;
}