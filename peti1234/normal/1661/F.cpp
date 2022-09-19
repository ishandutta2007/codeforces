#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, dif[c], k, sum, db;
long long calc(long long a, long long b) {
    return (a/b)*(a/b)*(b-a%b)+(a/b+1)*(a/b+1)*(a%b);
}
void solve(long long ert) {
    sum=0, db=0;
    for (int i=1; i<=n; i++) {
        long long x=dif[i], lo=0, hi=x, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (calc(x, mid)-calc(x, mid+1)>=ert) {
                lo=mid;
            } else {
                hi=mid;
            }
        }
        sum+=calc(x, hi), db+=hi-1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> dif[i];
    }
    cin >> k;
    long long s=0;
    for (int i=n; i>=1; i--) {
        dif[i]-=dif[i-1];
        s+=dif[i]*dif[i];
    }
    if (s<=k) {
        cout << 0 << "\n";
        return 0;
    }
    long long lo=0, hi=1e18, mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        solve(mid);
        if (sum>k) {
            hi=mid;
        } else {
            lo=mid;
        }
    }
    solve(hi);
    cout << db+(sum-k+lo-1)/lo << "\n";
    return 0;
}