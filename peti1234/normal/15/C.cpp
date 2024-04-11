#include <bits/stdc++.h>

using namespace std;
long long xo, n, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a >> b;
        if (b<10) {
            for (long long i=a; i<a+b; i++) {
                xo^=i;
            }
            continue;
        }
        b+=a;
        while (a%4) {
            xo^=a;
            a++;
        }
        while (b%4) {
            b--;
            xo^=b;
        }
    }
    cout << (xo? "tolik" : "bolik") << "\n";
    return 0;
}