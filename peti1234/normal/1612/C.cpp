#include <bits/stdc++.h>

using namespace std;
long long w, k, x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> k >> x;
        long long lo=0, hi=2*k-1, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            long long sum=0;
            if (mid<=k) sum=mid*(mid+1)/2;
            else {
                long long s=2*k-1-mid;
                sum=k*k-s*(s+1)/2;
            }
            if (sum>=x) hi=mid;
            else lo=mid;
        }
        cout << hi << "\n";
    }
    return 0;
}