#include <bits/stdc++.h>

using namespace std;
int w, n, ans[10005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            if (!ans[i]) {
                vector<int> sz;
                while (sz.size()<2 || sz[0]!=sz.back()) {
                    cout << "? " << i << endl;
                    int x;
                    cin >> x;
                    if (sz.size()>0) {
                        ans[sz.back()]=x;
                    }
                    sz.push_back(x);
                }
            }
        }
        cout << "! ";
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
            ans[i]=0;
        }
        cout.flush() << endl;
    }
    return 0;
}