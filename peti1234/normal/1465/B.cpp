#include <bits/stdc++.h>

using namespace std;
long long w, n, x, mar;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        while(true) {
            bool jo=1;
            x=n;
            while(x) {
                if (x%10 && n%(x%10)) jo=0;
                x/=10;
            }
            if (jo) {
                break;
            }
            n++;
        }
        cout << n << "\n";
    }
    return 0;
}