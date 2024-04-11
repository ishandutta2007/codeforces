#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,c,d,e,f,g,h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    int limo = b*c;
    limo /= g;
    int lime = d*e;
    int salt = f/h;
    int maz = min(limo,min(lime,salt));
    cout << maz/a;
    return 0;
}