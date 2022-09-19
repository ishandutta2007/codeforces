#include <bits/stdc++.h>

using namespace std;
const int c=200002;
map<int, int> m;
int w, n, ans[c], maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        m.clear();
        maxi=0;
        for (int i=1; i<=n; i++) {
            ans[i]=0;
        }
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            m[x]++;
            int ert=m[x];
            ans[ert]+=ert;
        }
        for (int i=1; i<=n; i++) {
            maxi=max(maxi, ans[i]);
        }
        cout << n-maxi << "\n";
    }
    return 0;
}