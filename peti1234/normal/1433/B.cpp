#include <bits/stdc++.h>

using namespace std;
int w, n, t[52], a, b, db;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, a=0, b=0, db=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (t[i] && !a) a=i;
            if (t[i]) b=i;
            else db++;
        }
        cout << db-n+b-a+1 << "\n";
    }
    return 0;
}