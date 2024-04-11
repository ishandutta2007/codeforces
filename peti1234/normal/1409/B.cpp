#include <bits/stdc++.h>

using namespace std;
int w;
long long a, b, x, y, n, mini, ak, bk, ae, be;
int main()
{
    cin >> w;
    while(w--) {
        cin >> a >> b >> x >> y >> n;
        ak=min(n, a-x), ae=a-ak, bk=min(n, b-y), be=b-bk;
        if (ae<be) a=ae, n-=ak;
        else b=be, n-=bk;
        a-=min(n, a-x), b-=min(n, b-y);
        cout << a*b << "\n";
    }
    return 0;
}