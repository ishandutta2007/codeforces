#include <bits/stdc++.h>

using namespace std;
long long w, n;
vector<long long> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        sz.clear();
        long long sum=0;
        for (int i=1; i<=n; i++) {
            long long x;
            cin >> x;
            sz.push_back(x);
            sum=max(sum, x);
        }
        sort(sz.begin(), sz.end());
        for (long long i=0; i<n-1; i++) {
            sum-=(sz[i+1]-sz[i])*(i+1)*(n-i-1);
        }
        cout << sum << "\n";
    }
    return 0;
}