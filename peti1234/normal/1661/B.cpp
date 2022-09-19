#include <bits/stdc++.h>

using namespace std;
int n, mod=32768;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, mini=20;
        cin >> x;
        if (x==0) {
            cout << 0 << "\n";
            continue;
        }
        for (int i=0; i<=20; i++) {
            mini=min(mini, i+15-__builtin_ctz(x+i));
        }
        cout << mini << "\n";
    }
    return 0;
}