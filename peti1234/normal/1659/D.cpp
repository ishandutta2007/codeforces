#include <bits/stdc++.h>

using namespace std;
int w, n, ans[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        int pos=0;
        for (int i=1; i<=n; i++) {
            ans[i]=1;
        }
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            x=n-x;
            if (pos==i-1 && x==n) {
                ans[i]=0;
                pos++;
                continue;
            }
            if (!ans[i]) {
                x-=i-1;
            }
            pos=n+1-x;
            ans[pos]=0;
        }
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}