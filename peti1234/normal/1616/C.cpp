#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, t[105], maxi=2;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int a=1; a<=n; a++) {
            for (int b=a+1; b<=n; b++) {
                int db=0;
                for (int c=1; c<=n; c++) {
                    if ((b-a)*(t[c]-t[a])==(c-a)*(t[b]-t[a])) db++;
                }
                maxi=max(maxi, db);
            }
        }
        maxi=min(maxi, n);
        cout << n-maxi << "\n";
    }
    return 0;
}