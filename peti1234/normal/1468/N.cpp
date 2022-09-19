#include <bits/stdc++.h>

using namespace std;
int w, t[3], k[5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        bool jo=1;
        for (int i=0; i<3; i++) {
            cin >> t[i];
        }
        for (int i=0; i<5; i++) {
            cin >> k[i];
            if (i<3) {
                t[i]-=k[i];
                if (t[i]<0) jo=0;
            }
        }
        k[3]-=t[0];
        t[2]-=max(0, k[3]);
        k[4]-=t[1];
        t[2]-=max(0, k[4]);
        if (t[2]<0) {
            jo=0;
        }
        cout << (jo? "YES" : "NO") << "\n";
    }
    return 0;
}
/*
1
2 2 3
1 2 3 0 1
*/