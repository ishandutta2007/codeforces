#include <bits/stdc++.h>

using namespace std;
int t[3], w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=0; i<3; i++) {
            t[i]=0;
        }
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            t[x%3]++;
        }
        int ans=0;
        for (int j=1; j<=3; j++) {
            for (int i=0; i<3; i++) {
                if (t[i]>n/3) {
                    ans+=t[i]-n/3;
                    t[(i+1)%3]+=t[i]-n/3;
                    t[i]=n/3;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}