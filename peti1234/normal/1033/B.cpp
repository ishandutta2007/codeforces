#include <bits/stdc++.h>

using namespace std;
long long w, a, b, c;
int main()
{
    cin >> w;
    while (w--) {
        cin >> a >> b;
        if (a-b>1) {
            cout << "NO\n";
            continue;
        }
        c=a+b;
        bool v=0;
        for (long long i=2; i*i<=c; i++) {
            if (c%i==0) {
                v=1;
            }
        }
        cout << (v ? "NO" : "YES") << "\n";
    }
    return 0;
}