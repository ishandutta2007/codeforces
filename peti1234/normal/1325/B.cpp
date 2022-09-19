#include <bits/stdc++.h>

using namespace std;
int w, n, db, t[100002];
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, db=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        sort(t+1, t+n+1);
        for (int i=1; i<=n; i++) db+=(t[i]!=t[i-1]);
        cout << db << "\n";
    }
    return 0;
}