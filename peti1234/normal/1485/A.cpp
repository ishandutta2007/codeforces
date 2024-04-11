#include <bits/stdc++.h>

using namespace std;
long long w, a, b, mini, db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        mini=1000, db=0;
        if (b==1) {
            b++, db++;
        }
        for (int i=1; i<=20; i++) {
            int x=a, ert=0;
            while (x) {
                x/=b, ert++;
            }
            mini=min(mini, ert+db);
            b++, db++;
        }
        cout << mini << "\n";
    }
    return 0;
}