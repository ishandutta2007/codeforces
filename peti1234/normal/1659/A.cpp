#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, r, b;
        cin >> n >> r >> b;
        int db=(r+b)/(b+1), bb=b;
        for (int i=0; i<bb; i++) {
            int db=r/(b+1);
            for (int j=0; j<db; j++) {
                cout << "R";
                r--;
            }
            cout << "B";
            b--;
        }
        for (int i=0; i<r; i++) {
            cout << "R";
        }
        cout << "\n";
    }
    return 0;
}