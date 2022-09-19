#include <bits/stdc++.h>

using namespace std;
int w, n, x, a[52], b[52];
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> x;
        for (int i=1; i<=n; i++) cin >> a[i];
        for (int i=1; i<=n; i++) cin >> b[i];
        sort(a+1, a+n+1), sort(b+1, b+n+1);
        int baj=0;
        for (int i=1; i<=n; i++) {
            if (a[i]+b[n+1-i]>x) baj=1;
        }
        if (baj) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}