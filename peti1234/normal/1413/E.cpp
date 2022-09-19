#include <bits/stdc++.h>

using namespace std;
int w;
long long a, b, c, d, e, f;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> a >> b >> c >> d;
        if (a>b*c) cout << -1 << "\n";
        else {
            e=a/b, f=e/d+1;
            cout << f*a-b*d*(f-1)*f/2 << "\n";

        }
    }
    return 0;
}