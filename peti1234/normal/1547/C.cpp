#include <bits/stdc++.h>

using namespace std;
const int c=105;
int w, len, x, y, a[c], b[c];
vector<int> ans;
int main()
{
    cin >> w;
    while (w--) {
        cin >> len >> x >> y;
        for (int i=1; i<=x; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=y; i++) {
            cin >> b[i];
        }
        int pos=1;
        bool baj=0;
        for (int i=1; i<=x; i++) {
            while (pos<=y && b[pos]<=len) {
                ans.push_back(b[pos]);
                if (!b[pos]) {
                    len++;
                }
                pos++;
            }
            if (a[i]>len) {
                baj=1;
            }
            ans.push_back(a[i]);
            if (!a[i]) {
                len++;
            }
        }
        while (pos<=y && b[pos]<=len) {
            ans.push_back(b[pos]);
            if (!b[pos]) {
                len++;
            }
            pos++;
        }
        if (pos<=y) {
            baj=1;
        }
        if (baj) {
            cout << -1 << "\n";
        } else {
            for (auto x:ans) {
                cout << x << " ";
            }
            cout << "\n";
        }
        ans.clear();
    }
    return 0;
}