#include <bits/stdc++.h>

using namespace std;
int w, n, t[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> t[i];
        sort(t+1, t+n+1);
        for (int i=n; i>=0; i--) {
            if (t[i]<=i) {
                cout << i+1 << "\n";
                break;
            }
        }
    }
    return 0;
}