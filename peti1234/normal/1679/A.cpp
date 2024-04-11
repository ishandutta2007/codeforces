#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long w;
    cin >> w;
    while (w--) {
        long long x, y;
        cin >> x;
        y=x;
        if (x%2 || x==2) {
            cout << -1 << "\n";
            continue;
        }
        long long ans=0;
        if (x%4==2) {
            x-=6;
            ans++;
        }
        long long a=ans, b=ans+2*(x/12);
        cout << b+(y-6*b)/4 << " " << a+(y-6*a)/4 << "\n";
    }
    return 0;
}