#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long w, n, t[c], kom[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            kom[i]=kom[i-1]+t[i];
        }
        bool baj=0;
        for (int i=1; i<=n; i++) {
            if (kom[i]<=kom[0]) {
                baj=1;
            }
        }
        for (int i=0; i<n; i++) {
            if (kom[i]>=kom[n]) {
                baj=1;
            }
        }
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}