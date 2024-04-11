#include <bits/stdc++.h>

using namespace std;
int w, n;
bool jo[10];
int main()
{
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<10; i++) jo[i]=0;
        for (int i=9; i>=1; i--) {
            if (n>=i) {
                n-=i, jo[i]=1;
            }
        }
        if (n) {
            cout << -1 << "\n";
        }
        else {
            for (int i=1; i<=9; i++) {
                if (jo[i]) {
                    cout << i;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}