#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long w, n, q, t[c], ans[c], sum, pos, maxi, si;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> q;
        sum=maxi=pos=0;
        sz.clear();
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            t[i]+=t[i-1];
            maxi=max(maxi, t[i]);
        }
        sum=t[n];
        for (int i=1; i<=q; i++) {
            ans[i]=0;
        }
        for (int i=1; i<=q; i++) {
            int x; cin >> x;
            if (sum>0 || x<=maxi) {
                if (x>maxi) {
                    long long kor=(x-maxi+sum-1)/sum;
                    ans[i]+=kor*n;
                    x-=kor*sum;
                }
                sz.push_back({x, i});
            }
        }
        si=sz.size();
        sort(sz.begin(), sz.end());
        for (int i=1; i<=n; i++) {
            while (pos<si && sz[pos].first<=t[i]) {
                ans[sz[pos].second]+=i;
                pos++;
            }
        }
        for (int i=1; i<=q; i++) {
            cout << ans[i]-1 << " ";
        }
        cout << "\n";
    }
    return 0;
}