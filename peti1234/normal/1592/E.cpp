#include <bits/stdc++.h>

using namespace std;
const int c2=20, c=1<<c2;
int n, xo, x, ut[c2], ans;
vector<int> sz[2*c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=c2-1; i>=0; i--) {
        sz[1<<(c2-i)].push_back(0);
    }
    for (int i=1; i<=n; i++) {
        cin >> x;
        xo^=x;
        //cout << "ertek " << xo << "\n";
        for (int j=c2-1; j>=0; j--) {
            int s=(1<<(c2-j))+(xo>>j);
            //cout << "hol " << j << " " << s << "\n";
            sz[s].push_back(i);
            if ((x & (1<<j))==0) {
                ut[j]=i;
            } else {
                int lo=-1, hi=sz[s].size(), mid;
                while (hi-lo>1) {
                    mid=(hi+lo)/2;
                    if (sz[s][mid]>=ut[j]) {
                        hi=mid;
                    } else {
                        lo=mid;
                    }
                }
                if (hi!=sz[s].size()) {
                    ans=max(ans, i-sz[s][hi]);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
/*
2
5 6
*/