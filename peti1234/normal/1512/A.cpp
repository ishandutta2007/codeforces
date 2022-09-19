#include <bits/stdc++.h>

using namespace std;
int w, n, t[102];
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        int pos=-1;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (t[i]!=t[1]) {
                if (pos==-1) {
                    pos=i;
                } else {
                    pos=1;
                }
            }
        }
        cout << pos << "\n";
    }
    return 0;
}