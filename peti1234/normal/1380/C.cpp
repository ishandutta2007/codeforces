#include <bits/stdc++.h>

using namespace std;
int w, n, x, cnt, db, mini, t[100002];
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> x, cnt=0, db=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        sort(t+1, t+n+1);
        for (int i=n; i>=1; i--) {
            db++;
            if (db*t[i]>=x) cnt++, db=0;
        }
        cout << cnt << "\n";
    }
    return 0;
}