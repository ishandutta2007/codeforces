#include <bits/stdc++.h>

using namespace std;
long long w, n, k, cnt, sum;
vector<long long> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=k; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
        }
        sort(sz.rbegin(), sz.rend());
        for (auto x:sz) {
            if (sum+n-x<n) {
                cnt++;
                sum+=n-x;
            }
        }
        cout << cnt << "\n";
        cnt=sum=0;
        sz.clear();
    }
    return 0;
}