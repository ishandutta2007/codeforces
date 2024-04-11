#include <bits/stdc++.h>

using namespace std;
int w, x, y, n, d, pos;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> y >> x;
        x-=y, d=x;
        for (int i=2; i<=n-1; i++) if (x%i==0) d=x/i;
        x+=y, pos=x;
        while(pos>0 && n>0) cout << pos << " ", pos-=d, n--;
        pos=x+d;
        while(n>0) cout << pos << " ", pos+=d, n--;
        cout << "\n";
    }
    return 0;
}