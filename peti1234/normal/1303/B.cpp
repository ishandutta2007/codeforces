#include <bits/stdc++.h>

using namespace std;
long long w, db, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> db >> a >> b;
        long long lo=db-1, hi=1e18, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            long long s=mid/(a+b)*a+min(a, mid%(a+b));
            if (2*s>=db) {
                hi=mid;
            } else {
                lo=mid;
            }
        }
        cout << hi << "\n";
    }
    return 0;
}