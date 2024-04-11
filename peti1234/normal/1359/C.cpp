#include <bits/stdc++.h>

using namespace std;
long long w, h, c, t;
int main()
{
    cin >> w;
    while(w--) {
        cin >> h >> c >> t;
        if (2*t<=h+c) cout << 2 << "\n";
        else {
            long long x=0, y=1000002;
            while(y-x>1) {
                long long z=(x+y)/2;
                if (h*(z+1)+c*z>=(2*z+1)*t) x=z;
                else y=z;
            }
            double xx=x, yy=y;
            double p=((xx+1)*h+xx*c)/(2*xx+1)-t, q=t-((yy+1)*h+yy*c)/(2*yy+1);
            if (p<q+1e-12) cout << 2*x+1 << "\n";
            else cout << 2*y+1 << "\n";
        }
    }
    return 0;
}