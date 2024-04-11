#include <bits/stdc++.h>

using namespace std;
long long poz, neg, a=1, b, val=1, n, x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        if (x<0) {
            val=1-val;
        }
        if (val) {
            poz+=a, neg+=b;
            a++;
        } else {
            neg+=a, poz+=b;
            b++;
        }
    }
    cout << neg << " " << poz << "\n";
    return 0;
}