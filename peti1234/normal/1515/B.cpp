#include <bits/stdc++.h>

using namespace std;
long long w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        if (n%2) {
            cout << "NO\n";
        } else {
            n/=2;
            long long x=sqrt(n), y=sqrt(n/2);
            if (x*x==n || y*y*2==n) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}