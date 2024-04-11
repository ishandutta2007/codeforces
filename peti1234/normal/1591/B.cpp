#include <bits/stdc++.h>

using namespace std;
int w, n, t[200005], ut, cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        ut=0, cnt=0;
        for (int i=n; i>=1; i--) {
            if (t[i]>ut) {
                cnt++;
                ut=t[i];
            }
        }
        cout << cnt-1 << "\n";
    }
    return 0;
}