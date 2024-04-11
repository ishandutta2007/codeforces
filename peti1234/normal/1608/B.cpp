#include <bits/stdc++.h>

using namespace std;
int w, n, a, b, ans[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> a >> b;
        if (a+b>n-2 || abs(a-b)>1) {
            cout << "-1\n";
        } else {
            if (a==0 && b==0) {
                for (int i=1; i<=n; i++) {
                    cout << i << " ";
                }
                cout << "\n";
                continue;
            }
            int ka=(a>b ? 0 : 1), kb=1-ka;
            for (int i=1; i<=n; i++) ans[i]=0;
            for (int i=1; i<=a; i++) {
                ans[2*i+ka]=n+1-i;
            }
            for (int i=1; i<=b; i++) {
                ans[2*i+kb]=i;
            }
            ans[1]=b+1;
            int ert=b+1;
            if (a>=b) {
                for (int i=n; i>=1; i--) {
                    if (!ans[i]) {
                        ans[i]=++ert;
                    }
                }
            } else {
                for (int i=1; i<=n; i++) {
                    if (!ans[i]) {
                        ans[i]=++ert;
                    }
                }
            }
            for (int i=1; i<=n; i++) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}