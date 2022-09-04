#include <bits/stdc++.h>

using namespace std;
typedef long double dl;
typedef long long ll;
int main()
{
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    dl a, b;
    cin >> a >> b;
    if (a < b){
        cout << -1;
        return 0;
    }
    if (a == b){
        cout << setprecision(10) << a;
        return 0;
    }
    dl ans;
    ll l = 0, r = 1e18;
    while (r - l > 1){
        ll m = (l + r) / 2;
        if ((a + b) / (2.0 * dl(m)) >= b)
            l = m;
        else
            r = m;
    }
    ans = (l == 0 ? -1 : (a + b) / (2.0 * dl(l)));
    l = 0, r = 1e18;
    while (r - l > 1){
        ll m = (l + r) / 2;
        if ((a - b) / (2.0 * dl(m)) >= b)
            l = m;
        else
            r = m;
    }
    if (l != 0)
        ans = min(ans, (a - b) / (2.0 * dl(l)));
    if (ans == -1)
        cout << -1;
    else
        cout << setprecision(10) << ans;
}