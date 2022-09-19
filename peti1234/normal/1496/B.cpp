#include <bits/stdc++.h>

using namespace std;
int w, n, k, mex, maxi, cnt;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        cnt=0;
        sz.clear();
        sz.push_back(-1);
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            sz.push_back(x);
        }
        sort(sz.begin(), sz.end());
        maxi=sz.back(), mex=maxi+1;
        for (int i=1; i<=n; i++) {
            if (sz[i]-sz[i-1]>1) {
                mex=sz[i-1]+1;
                break;
            }
        }
        if (mex>maxi) {
            cout << mex+k << "\n";
        } else {
            if (k) {
                sz.push_back((mex+maxi+1)/2);
                sort(sz.begin(), sz.end());
                n++;
            }
            for (int i=1; i<=n; i++) {
                if (sz[i]!=sz[i-1]) {
                    cnt++;
                }
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}