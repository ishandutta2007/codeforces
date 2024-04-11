#include <bits/stdc++.h>

using namespace std;
long long x, y, po=2, lo, hi, mid;
long long solve(long long bal, long long jobb) {
    if (bal>x) {
        return 0;
    }
    if (jobb%2==0) {
        return solve(bal, jobb+1);
    }
    jobb=min(jobb, x);
    long long kov=2*jobb+1;
    return jobb-bal+1+solve(2*bal, kov);
}
int main()
{
    cin >> x >> y;
    while (solve(po, po)>=y) {
        po*=2;
    }
    po/=2;
    lo=po, hi=2*po;
    while (hi-lo>2) {
        mid=(hi+lo)/2;
        if (mid%2) {
            mid++;
        }
        if (solve(mid, mid)>=y) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    if (solve(lo+1, lo+1)>=y) {
        lo++;
    }
    cout << lo << "\n";
    return 0;
}