#include <bits/stdc++.h>

using namespace std;
int w, n, t[102], k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        t[n]+=k;
        for (int i=1; i<=n; i++) {
            int s=min(t[i], k);
            t[i]-=s;
            k-=s;
            cout << t[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}