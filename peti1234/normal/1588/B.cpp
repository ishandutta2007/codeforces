#include <bits/stdc++.h>

using namespace std;
long long kerd(long long a, long long b) {
    cout.flush() << "? " << a << " " << b << endl;
    long long ans;
    cin >> ans;
    return ans;
}
long long w, n, inv;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        long long lo=1, hi=n+1, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (kerd(1, mid)>=1) {
                hi=mid;
            } else {
                lo=mid;
            }
        }
        inv=kerd(lo, n);
        long long s=inv-kerd(lo+1, n), p1=lo, p2=lo+s+1, dif=inv-s*(s+1)/2;
        long long p3=p2+sqrt(2*dif);
        cout.flush() << "! " << p1 << " " << p2 << " " << p3 << endl;
    }
    return 0;
}