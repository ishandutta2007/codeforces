#include <bits/stdc++.h>

using namespace std;
long long n, k, x, ans;
vector<long long> sz, sz2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> x;
    for (int i=1; i<=n; i++) {
        long long a;
        cin >> a;
        sz.push_back(a);
    }
    sort(sz.begin(), sz.end());
    for (int i=1; i<n; i++) {
        sz2.push_back(sz[i]-sz[i-1]);
    }
    sort(sz2.begin(), sz2.end());
    ans=n;
    for (auto f:sz2) {
        long long s=(f-1)/x;
        if (s<=k) {
            if (s>=0) {
                k-=s;
            }
            ans--;
        }
    }
    cout << ans << "\n";
    return 0;
}