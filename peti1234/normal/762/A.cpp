#include <bits/stdc++.h>

using namespace std;
long long n, k;
vector<long long> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (long long i=1; i*i<=n; i++) {
        if (n%i==0) {
            sz.push_back(i);
            if (i*i<n) {
                sz.push_back(n/i);
            }
        }
    }
    sort(sz.begin(), sz.end());
    if (sz.size()<k) {
        cout << -1 << "\n";
    } else {
        cout << sz[k-1] << "\n";
    }
    return 0;
}