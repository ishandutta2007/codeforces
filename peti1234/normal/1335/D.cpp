#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> w;
    while(w--) {
        for (int i=1; i<=9; i++) {
            for (int j=1; j<=9; j++) {
                char x;
                cin >> x;
                if (x=='2') x='1';
                cout << x;
            }
            cout << "\n";
        }
    }
    return 0;
}