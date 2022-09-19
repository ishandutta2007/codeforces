#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        if (n<10) {
            char c='a';
            for (int i=1; i<=n; i++) {
                cout << c;
                c++;
            }
            cout << "\n";
        } else {
            int f=n/2-1;
            for (int i=1; i<=f; i++) {
                cout << 'a';
            }
            cout << 'b';
            for (int i=1; i<=f+1; i++) {
                cout << 'a';
            }
            if (n%2) {
                cout << 'c';
            }
            cout << "\n";
        }
    }
    return 0;
}