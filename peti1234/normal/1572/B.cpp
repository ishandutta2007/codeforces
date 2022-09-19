#include <bits/stdc++.h>

using namespace std;
int w, n, xo, pos;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            xo^=x;
            if (xo==0 && i%2==1) {
                pos=i;
            }
        }
        if (xo==0 && pos) {
            for (int i=1; i<pos; i+=2) {
                ans.push_back(i);
            }
            for (int i=pos-4; i>=1; i-=2) {
                ans.push_back(i);
            }
            if (n%2==0) {
                pos++;
            }
            for (int i=pos; i+2<=n; i+=2) {
                ans.push_back(i);
            }
            for (int i=n-4; i>=pos; i-=2) {
                ans.push_back(i);
            }

            cout << "YES\n";
            cout << ans.size() << "\n";
            for (auto x:ans) {
                cout << x << " ";
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
        xo=0, pos=0, ans.clear();
    }
    return 0;
}