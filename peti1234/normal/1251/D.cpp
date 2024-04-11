#include <bits/stdc++.h>

using namespace std;
long long w, n, sum;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> sum;
        for (int i=1; i<=n; i++) {
            int x, y;
            cin >> x >> y;
            sz.push_back({x, y});
        }
        sort(sz.rbegin(), sz.rend());
        long long lo=1, hi=2e9, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            long long sum2=0, db=0;
            for (auto x:sz) {
                long long fi=x.first, se=x.second;
                if (se>=mid && db<(n+1)/2) {
                    sum2+=max(fi, mid);
                    db++;
                } else {
                    sum2+=fi;
                }
            }
            if (sum2<=sum && 2*db>n) {
                lo=mid;
            } else {
                hi=mid;
            }
        }
        sz.clear();
        cout << lo << "\n";
    }
    return 0;
}