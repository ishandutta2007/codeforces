#include <bits/stdc++.h>

using namespace std;
long long n, p, a, b;
int main()
{
    cin >> n >> p >> a >> b;
    for (int i=0; i<=a; i++) {
        long long s=p-i*b;
        if (s>=0 && s%a==0 && i+s/a<=n) {
            cout << s/a << " " << i << " " << n-i-s/a << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}