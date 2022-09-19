#include <bits/stdc++.h>

using namespace std;
int w, x;
int main()
{
    cin >> w;
    while (w--) {
        cin >> x;
        while (x>0) {
            if (x%11==0) {
                x=0;
            } else {
                x-=111;
            }
        }
        cout << (x==0 ? "YES" : "NO") << "\n";
    }
    return 0;
}