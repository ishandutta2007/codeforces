#include <bits/stdc++.h>

using namespace std;
int t[200001], w, n, mini;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        mini=2e9;
        for (int i=1; i<=n; i++) {
            t[i]=0;
        }
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (t[x]!=0) {
                mini=min(mini, i-t[x]);
            }
            t[x]=i;
        }
        if (mini==2e9) {
            cout << -1;
        } else {
            cout << mini+1;
        }
        cout << "\n";
    }
    return 0;
}