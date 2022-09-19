#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, val[c], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int j=0; j<2; j++) {
            for (int i=0; i<n; i++) {
                int x;
                cin >> x;
                val[x]=i;
            }
        }
        for (int i=3; i<=2*n; i+=2) {
            val[i]=min(val[i], val[i-2]);
        }
        for (int i=2*n-2; i>=2; i-=2) {
            val[i]=min(val[i], val[i+2]);
        }
        ans=n;
        for (int i=1; i<=2*n; i+=2) {
            ans=min(ans, val[i]+val[i+1]);
        }
        cout << ans << "\n";
    }
    return 0;
}