#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        bool t[10][10];
        for (int i=1; i<=8; i++) {
            for (int j=1; j<=8; j++) {
                char c;
                cin >> c;
                t[i][j]=(c=='#');
            }
        }
        for (int i=2; i<8; i++) {
            for (int j=2; j<8; j++) {
                if (t[i][j] && t[i-1][j-1] && t[i-1][j+1]) {
                    cout << i << " " << j << "\n";
                }
            }
        }
    }
    return 0;
}