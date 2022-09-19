#include <bits/stdc++.h>

using namespace std;
int w;
int n, t[52], mini;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> t[i];
        sort(t+1, t+n+1);
        mini=t[2]-t[1];
        for (int i=3; i<=n; i++) mini=min(mini, t[i]-t[i-1]);
        cout << mini << "\n";
    }
    return 0;
}