#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int n; cin >> n;
        if (n) {
            cout << 9;
            n--;
        }
        if (n) {
            cout << 8;
            n--;
        }
        for (int i=1; i<=n; i++) {
            cout << (i+8)%10;
        }
        cout << "\n";
    }
    return 0;
}