#include <bits/stdc++.h>

using namespace std;
int w, n, t[10002];
int kerd(int a, int b, int c, int d) {
    cout.flush() << "? " << a << " " << b << " " << c << " " << d << "\n";
    int x;
    cin >> x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        int lo=0, hi=n, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (kerd(2, 1, 2, mid)>mid) {
                lo=mid;
            } else {
                hi=mid;
            }
        }
        t[1]=hi;
        for (int i=2; i<=n; i++) {
            if (2*hi>n) {
                int s=kerd(2, i, 1, 1);
                if (s<hi) {
                    t[i]=s;
                } else {
                    t[i]=kerd(1, 1, i, n-1);
                }
            } else {
                int s=kerd(1, 1, i, n-1);
                if (s>hi) {
                    t[i]=s;
                } else {
                    t[i]=kerd(2, i, 1, 1);
                }
            }
        }
        cout.flush() << "! ";
        for (int i=1; i<=n; i++) {
            cout << t[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}