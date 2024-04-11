#include <bits/stdc++.h>

using namespace std;
int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n, x;
        vector<int> ans;
        cin >> n >> x;
        ans.push_back(x);
        bool baj=0;
        for (int i=1; i<n; i++) {
            int y;
            cin >> y;
            if (y && x>=y) baj=1;
            x+=y;
            ans.push_back(x);
        }
        if (baj) {
            cout << -1 << "\n";
        } else {
            for (auto x:ans) {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}