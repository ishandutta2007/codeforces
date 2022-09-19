#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int a, b, c, d;
        int x, y, xk, yk, xn, yn;
        cin >> a >> b >> c >> d >> x >> y>> xk >> yk >> xn >> yn;
        if ((b-a<=xn-x && a-b<=x-xk && (xk!=xn || a==0)) && (d-c<=yn-y && c-d<=y-yk && (yk!=yn || c==0))) cout << "YES" << "\n";
        else cout << "NO" << "\n";

    }
    return 0;
}
// Gyorsabban is mehetett volna.