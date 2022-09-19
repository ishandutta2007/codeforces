#include <bits/stdc++.h>

using namespace std;
int a, b, c, d;
int main()
{
    cin >> a >> b >> c >> d;
    for (int i=max(b, d); i<=15000; i++) {
        if ((i-b)%a==0 && (i-d)%c==0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}