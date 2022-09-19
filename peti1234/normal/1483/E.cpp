#include <bits/stdc++.h>

using namespace std;
bool sajat;
long long w, lo, hi, sum;
long long ans, db;
bool kerd(long long x) {
    if (x>=hi) {
        return 0;
    }
    cout.flush() << "? " << x << "\n";
    string s;
    cin >> s;
    if (s[0]=='L') {
        sum+=x;
        lo=x;
    } else {
        sum-=x;
        hi=x;
    }
    return (s[0]=='L');
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        lo=0, hi=1e14+1, sum=1;
        while (kerd(sum));
        while (hi-lo>1) {
            if (sum<=lo) {
                kerd(lo);
                continue;
            }
            double pr=0.18+sqrt(sum/lo)/7;
            long long s=ceil(lo*(1-pr)+hi*pr);
            kerd(max(lo+1, min({hi-1, sum, s})));
        }
        cout.flush() << "! " << lo << "\n";
    }
    return 0;
}