#include <bits/stdc++.h>

using namespace std;
int t[4], s;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=0; i<4; i++) cin >> t[i], s+=t[i];
    for (int i=0; i<8; i++) {
        int x=0;
        for (int j=0; j<3; j++) if (i & (1<<j)) x+=t[j];
        if (2*x==s) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}