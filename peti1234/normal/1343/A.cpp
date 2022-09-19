#include <bits/stdc++.h>

using namespace std;
int w;
long long x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> x, y=3;
        while(true) {
            if (x%y==0) {
                cout << x/y << "\n";
                break;
            }
            y*=2, y++;
        }

    }
    return 0;
}