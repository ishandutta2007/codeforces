#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        bool jo=0;
        for (int i=1; i<=30; i++) {
            if ((1<<i)==n) {
                cout << (i%2 ? "Bob" : "Alice");
                jo=1;
            }
        }
        if (!jo) {
            cout << (n%2 ? "Bob" : "Alice");
        }
        cout << "\n";
    }
    return 0;
}