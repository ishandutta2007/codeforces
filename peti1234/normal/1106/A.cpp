#include <bits/stdc++.h>

using namespace std;
int n;
int x;
int t[502][502];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            char c;
            cin >> c;
            if (c=='X') {
                t[i][j]=1;
            }
        }
     }
     for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (t[i-1][j-1]+t[i+1][j-1]+t[i-1][j+1]+t[i+1][j+1]+t[i][j]==5) {
                x++;
            }
        }
    }
    cout << x << endl;
    return 0;
}