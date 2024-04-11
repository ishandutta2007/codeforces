#include <bits/stdc++.h>

using namespace std;
int a, b, c, d, e, f, ans;
int main()
{
    cin >> a >> b >> c >> d >> e >> f;
    if (e>f) {
        while (a && d) {
            ans+=e, a--, d--;
        }
    }
    if (f>=e) {
        while (b && c && d) {
            ans+=f, b--, c--, d--;
        }
    }
    while (a && d) {
        ans+=e, a--, d--;
    }
    while (b && c && d) {
        ans+=f, b--, c--, d--;
    }
    cout << ans << "\n";
    return 0;
}