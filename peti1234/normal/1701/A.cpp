#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int a, b, c, d, sum;
        cin >> a >> b >> c >> d;
        sum=a+b+c+d;
        if (sum==0) cout << 0 << "\n";
        else if (sum==4) cout << 2 << "\n";
        else cout << 1 << "\n";
    }
    return 0;
}