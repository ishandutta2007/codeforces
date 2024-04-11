#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, kis=-1, nagy=1e6, ans[c], t[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    t[n+1]=1e6;
    for (int i=1; i<=n; i++) {
        bool a=(t[i]>kis), b=(t[i]<nagy);
        if (!a && !b) {
            cout << "NO\n";
            return 0;
        }
        if (a && b) {
            if (t[i+1]>t[i]) b=0;
            else a=0;
        }
        if (a) {
            kis=t[i];
        } else {
            nagy=t[i];
            ans[i]=1;
        }
    }
    cout << "YES\n";
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}