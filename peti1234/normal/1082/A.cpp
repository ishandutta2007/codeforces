#include <bits/stdc++.h>

using namespace std;
int t;
int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if (abs(b-c)%d==0) {
            cout << abs(b-c)/d << endl;
            continue;
        }
        long long mini=INT_MAX;
        if (abs(a-c)%d==0) {
            mini=min(mini, (a-b-1+d)/d+(a-c-1+d)/d);
        }
        if (abs(c-1)%d==0) {
            mini=min(mini, (b-2+d)/d+(c-2+d)/d);
        }
        if (mini==INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << mini << endl;
        }
    }
    return 0;
}