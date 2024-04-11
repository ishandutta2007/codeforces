#include <bits/stdc++.h>

using namespace std;
long long n, k, ans;
vector<long long> a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (long long i=0; i<n; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.rbegin(), a.rend());
    ans=a[n/2];
    for (long long i=n/2; i>=0; i--) {
        long long cnt=n/2-i+1, maxi=(i>0 ? a[i-1]-a[i] : 1e9), ert=min(maxi, k/cnt);
        ans+=ert, k-=cnt*ert;
    }
    cout << ans << "\n";
    return 0;
}