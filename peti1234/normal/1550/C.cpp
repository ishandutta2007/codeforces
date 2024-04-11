#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, ans, w, x[c];
bool jo(int a, int b, int c) {
    return (x[b]<min(x[a], x[c]) || x[b]>max(x[a], x[c]));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> x[i];
        }
        ans=2*n-1;
        for (int i=1; i<=n-2; i++) {
            ans+=jo(i, i+1, i+2);
        }
        for (int i=1; i<=n-3; i++) {
            if (jo(i, i+1, i+2) && jo(i, i+1, i+3) && jo(i, i+2, i+3) && jo(i+1, i+2, i+3)) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}