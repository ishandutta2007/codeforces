#include <bits/stdc++.h>

using namespace std;
int w, n, t[200002], db, cnt;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, db=0, cnt=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        sort(t+1, t+n+1);
        for (int i=1; i<=n; i++) {
            cnt++;
            if (cnt>=t[i]) db++, cnt=0;
        }
        cout << db << "\n";
    }
    return 0;
}