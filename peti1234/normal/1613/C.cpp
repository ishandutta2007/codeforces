#include <bits/stdc++.h>

using namespace std;
long long w, n, h;
vector<long long> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> h;
        for (int i=0; i<n; i++) {
            long long x;
            cin >> x;
            s.push_back(x);
        }
        long long lo=0, hi=1e18, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            long long sum=mid;
            for (int i=0; i<n-1; i++) {
                sum+=min(mid, s[i+1]-s[i]);
            }
            if (sum>=h) {
                hi=mid;
            } else {
                lo=mid;
            }
        }

        cout << hi << "\n";
        s.clear();
    }
    return 0;
}