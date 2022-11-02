#include <bits/stdc++.h>
#define int long long
using namespace std;
pair<int, int> euclid(int x, int y)
{
    long long a=x, ax=1, ay=0, b=y, bx=0, by=1, c, cx, cy;
    while (b!=0)
    {
        long long pom=a/b;
        c=a; cx=ax; cy=ay;
        a=b; ax=bx; ay=by;
        b=c%a; bx=cx-pom*ax; by=cy-pom*ay;
        bx%=y;
        by%=x;
    }
    return {ax, ay};
}
int32_t main()
{
    int n;
    cin >> n;
    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i==0)
        {
            int x=1, y=n;
            while (y%i==0)
            {
                x*=i;
                y/=i;
            }
            if (y==1)
                break;
            if (x<y)
                swap(x, y);
            pair<int, int> para = euclid(x, y);
            int a=para.first, b=para.second;
            if (a<0)
                a+=y;
            if (b>0)
                b-=x;
            cout << "YES\n2\n";
            cout << -b << " " << x << "\n";
            cout << y-a << " " << y << "\n";
            return 0;
        }
    }
    cout << "NO\n";
}