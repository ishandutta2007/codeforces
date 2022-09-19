#include <bits/stdc++.h>

using namespace std;
long long n, m, db[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=m; i++) {
            int x;
            cin >> x;
            db[x]++;
        }
        long long lo=0, hi=2*m, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            long long cnt=0;
            for (int i=1; i<=n; i++) {
                long long s=min(db[i], mid);
                cnt+=s+(mid-s)/2;
            }
            if (cnt>=m) hi=mid;
            else lo=mid;
        }

        cout << hi << "\n";

        for (int i=1; i<=n; i++) {
            db[i]=0;
        }
    }
    return 0;
}