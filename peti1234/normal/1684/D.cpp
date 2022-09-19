#include <bits/stdc++.h>

using namespace std;
long long w, n, k, sum;
vector<long long> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        sum=-k*(k-1)/2;
        for (int i=1; i<=n; i++) {
            long long x;
            cin >> x;
            sum+=x;
            sz.push_back(x-(n-i));
        }
        sort(sz.rbegin(), sz.rend());
        for (int i=0; i<k; i++) {
            sum-=sz[i];
        }
        cout << sum << "\n";
        sz.clear();
    }
    return 0;
}