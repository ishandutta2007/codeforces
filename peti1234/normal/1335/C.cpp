#include <bits/stdc++.h>

using namespace std;
int w, n, k, mdb, e;
int t[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        k=0, mdb=1, e=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        sort(t+1, t+n+1);
        for (int i=1; i<=n; i++) {
            if (t[i]!=t[i-1]) k++, e=i-1;
            else mdb=max(mdb, i-e);
        }
        if (k==mdb) k--;
        cout << min(k, mdb) << "\n";
    }
    return 0;
}