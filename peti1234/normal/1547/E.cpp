#include <bits/stdc++.h>

using namespace std;
const int c=300005, sok=2e9;
int w, n, k, t[c], s[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            t[i]=sok;
        }
        for (int i=1; i<=k; i++) {
            cin >> s[i];
        }
        for (int i=1; i<=k; i++) {
            int x;
            cin >> x;
            t[s[i]]=x;
        }
        for (int i=2; i<=n; i++) {
            t[i]=min(t[i], t[i-1]+1);
        }
        for (int i=n-1; i>=1; i--) {
            t[i]=min(t[i], t[i+1]+1);
        }
        for (int i=1; i<=n; i++) {
            cout << t[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}