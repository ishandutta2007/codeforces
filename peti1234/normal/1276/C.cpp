#include <bits/stdc++.h>

using namespace std;
const int c=400002;
int n, t[c], no[c], ans[c],  db=1;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<=n; i++) for (long long j=i*i; j<=n; j+=i) no[j]=i;
    for (int i=1; i<=n; i++) cin >> t[i];
    sort(t+1, t+n+1);
    for (int i=2; i<=n; i++) {
        if (t[i]!=t[i-1]) sz.push_back({db, t[i-1]}), db=1;
        else db++;
    }
    sz.push_back({db, t[n]});
    sort(sz.rbegin(), sz.rend());
    for (int i=n; i>=1; i--) {
        int cnt=0, jo=1, p=no[i], q=i/p;
        for (int j=0; j<sz.size(); j++) {
            cnt+=max(0, sz[j].first-p);
            if (i+cnt>n) {
                jo=0;
                break;
            }
        }
        if (jo) {
            cout << i << "\n" << p << " " << q << "\n";
            int x=0, y=0, rem=i;
            for (int i=0; i<sz.size(); i++) {
                for (int j=0; j<min(sz[i].first, p) && rem>0; j++) {
                    ans[q*x+y+1]=sz[i].second;
                    x++, y++, x%=p, y%=q, rem--;
                    if (ans[q*x+y+1]) x++, x%=p;
                }
            }
            for (int j=1; j<=i; j++) {
                cout << ans[j] << " ";
                if (j%q==0) cout << "\n";
            }
            return 0;
        }
    }
    return 0;
}