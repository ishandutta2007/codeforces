#include <bits/stdc++.h>

using namespace std;
int n=8;
char p[8][8];
int main()
{
    int w;
    cin >> w;
    while (w--) {
        bool jo=0;
        for (int i=0; i<n; i++) {
            bool spec=1;
            for (int j=0; j<n; j++) {
                cin >> p[i][j];
                if (p[i][j]!='R') spec=0;
            }
            if (spec) jo=1;
        }
        cout << (jo ? "R" : "B") << "\n";
    }
    return 0;
}