#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        cout << "2\n";
        cout << n-1 << " " << n << "\n";
        for (int i=n-2; i>=1; i--) {
            cout << i << " " << i+2 << "\n";
        }
    }
    return 0;
}