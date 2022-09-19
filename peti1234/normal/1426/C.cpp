#include <bits/stdc++.h>

using namespace std;
int w, n, x, y;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, x=sqrt(n), y=2*(x-1);
        if (x*x==n) cout << y << "\n";
        else if (x*(x+1)>=n) cout << y+1 << "\n";
        else cout << y+2 << "\n";
    }
    return 0;
}