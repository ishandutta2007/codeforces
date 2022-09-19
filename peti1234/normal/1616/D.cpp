#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, y, ans=0, ut=0, mini=0;
        vector<int> sz;
        cin >> n;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
        }
        cin >> y;
        for (int i=0; i<n; i++) {
            int x=sz[i]-y;
            if (ut==0 || mini+x>=0) {
                ut=1, ans++;
                mini=min(x, mini+x);
            } else {
                ut=0, mini=0;
            }
        }
        //cout << "valasz........... ";
        cout << ans << "\n";
    }
    return 0;
}