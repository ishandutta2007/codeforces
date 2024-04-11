#include <bits/stdc++.h>

using namespace std;
long long w, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        if (b==1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            long long s=2*a*b;
            cout << a << " " << s-a << " " << s << "\n";

        }
    }
    return 0;
}