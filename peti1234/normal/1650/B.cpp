#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        long long a, l, r;
        cin >> l >> r >> a;
        if (a>1 && (r+1)/a>l/a && r%a<a-1) {
            r=r/a*a;
            r--;
        }
        cout << r/a+r%a << "\n";
    }
    return 0;
}