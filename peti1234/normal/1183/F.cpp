#include <bits/stdc++.h>

using namespace std;
bool v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, ans=0, ert, ert2=0;
        vector<int> sz;
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
            v[x]=1;
        }
        sort(sz.rbegin(), sz.rend());
        ert=sz[0];

        if (ert%30==0 && v[ert/2] && v[ert/3] && v[ert/5]) ans=ert/30*31;
        for (auto x:sz) {
            if (!ert2 && ert%x) ert2=x;
            else if (ert%x && ert2%x) {
                ans=max(ans, ert+ert2+x);
            }
        }
        ans=max(ans, ert+ert2);

        cout << ans << "\n";
        for (auto x:sz) {
            v[x]=0;
        }

    }
    return 0;
}