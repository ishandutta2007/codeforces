#include <bits/stdc++.h>

using namespace std;
int w, x;
int main()
{
    cin >> w;
    while(w--) {
        cin >> x;
        int p=(x%10-1)*10;
        if (x<10) cout << p+1;
        else if (x<100) cout << p+3;
        else if (x<1000) cout << p+6;
        else cout << p+10;
        cout << "\n";
    }
    return 0;
}