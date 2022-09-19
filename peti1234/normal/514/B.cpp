#include <bits/stdc++.h>

using namespace std;
set<pair<int, int> > s;
int n, a, b, x, y, g;
int main()
{
    cin >> n >> a >> b;
    for (int i=1; i<=n; i++) {
        cin >> x >> y;
        x-=a, y-=b, g=__gcd(x, y);
        x/=g, y/=g;
        if (x<0) {
            x*=-1, y*=-1;
        }
        s.insert({x, y});
    }
    cout << s.size() << "\n";
    return 0;
}