#include <bits/stdc++.h>

using namespace std;
int w, t[4];
int main()
{
    cin >> w;
    while(w--) {
        for (int i=0; i<4; i++) {
            cin >> t[i];
        }
        sort(t, t+4);
        cout << t[0]*t[2] << "\n";
    }
    return 0;
}