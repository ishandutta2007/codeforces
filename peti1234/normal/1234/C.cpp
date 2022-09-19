#include <bits/stdc++.h>

using namespace std;
int w, n, t[200005][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int j=0; j<2; j++) {
            for (int i=1; i<=n; i++) {
                char c;
                cin >> c;
                t[i][j]=(c=='1' || c=='2' ? 1 : 0);
            }
        }
        int pos=0;
        bool baj=0;
        for (int i=1; i<=n; i++) {
            if (!t[i][pos]) {
                pos=1-pos;
                if (t[i][pos]) {
                    baj=1;
                }
            }
        }
        cout << (pos && !baj ? "YES" : "NO") << "\n";
    }
    return 0;
}