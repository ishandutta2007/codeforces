#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        long long x, y, n, p;
        cin >> x >> y >> n;
        p=n-n%x;
        if (p+y>n) p-=x;
        cout << p+y << "\n";
    }
    return 0;
}