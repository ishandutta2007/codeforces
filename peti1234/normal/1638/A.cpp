#include <bits/stdc++.h>

using namespace std;
int w, n, t[505];
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        int pos=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (!pos && t[i]!=i) pos=i;
        }
        if (pos) {
            for (int i=pos; i<=n; i++) {
                if (t[i]==pos) {
                    reverse(t+pos, t+i+1);
                }
            }
        }
        for (int i=1; i<=n; i++) {
            cout << t[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}