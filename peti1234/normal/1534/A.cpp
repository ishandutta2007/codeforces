#include <bits/stdc++.h>

using namespace std;
int w, n, m;
string s[55];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        bool po=0, pe=0;
        for (int i=0; i<n; i++) {
            cin >> s[i];
            for (int j=0; j<m; j++) {
                char c=(s[i][j]);
                bool k=(i+j)%2;
                if ((c=='R' && k) || (c=='W' && !k)) {
                    pe=1;
                }
                if ((c=='R' && !k) || (c=='W' && k)) {
                    po=1;
                }
            }
        }
        if (po && pe) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            if (!po && !pe) {
                po=1;
            }
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    cout << ((i+j+po)%2 ? 'R' : 'W');
                }
                cout << "\n";
            }
        }
    }
    return 0;
}