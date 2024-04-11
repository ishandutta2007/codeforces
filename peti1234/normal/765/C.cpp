#include <bits/stdc++.h>

using namespace std;
long long k, a, b, n;
int main()
{
    cin >> k >> a >> b;
    if (min(a, b)<k && max(a,b)%k!=0) {
        cout << -1 << endl;
        return 0;
    }
    n=a/k;
    n+=b/k;
    if (n!=0) {
        cout << n << endl;
    } else {
    cout << -1;
    }
    return 0;
}