#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int st=t1*abs(x-y), el=t2*(abs(z-x)+abs(x-y))+3*t3;
    cout << (el<=st ? "YES" : "NO") << "\n";
    return 0;
}