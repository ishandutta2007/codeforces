#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long a=0, b=(1<<30);
int n, t[c];
int solve(int l, int r, long long a, long long b) {
    if (l>r) return 0;
    if (l==r) return 1;
    if (b-a==1) return 2;
    long long c=(a+b)/2;
    int lo=l-1, hi=r+1, mid;
    while(hi-lo>1) {
        mid=(hi+lo)/2;
        if (t[mid]<c) lo=mid;
        else hi=mid;
    }
    mid=lo;
    //cout << l << " " << r << " " << mid << " " << a << " " << b << " " << c << endl;
    int x=solve(l, mid, a, c), y=solve(mid+1, r, c, b);
    int ans=max(x, y);
    if (mid>=l) {
        ans=max(ans, 1+y);
    }
    if (mid<r) {
        ans=max(ans, 1+x);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    sort(t+1, t+n+1);
    //cout << solve(1, n, 0, 16) << endl;
    cout << n-solve(1, n, a, b) << "\n";
    return 0;
}