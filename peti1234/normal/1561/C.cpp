#include <bits/stdc++.h>

using namespace std;
int w, n;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int maxi=0, x, y;
            cin >> x;
            for (int j=1; j<=x; j++) {
                cin >> y;
                maxi=max(maxi, y+2-j);
            }
            sz.push_back({maxi, x});
        }
        sort(sz.begin(), sz.end());
        int maxi=0, sum=0;
        for (auto x:sz) {
            maxi=max(maxi, x.first-sum);
            sum+=x.second;
        }

        cout << maxi << "\n";
        sz.clear();
    }
    return 0;
}