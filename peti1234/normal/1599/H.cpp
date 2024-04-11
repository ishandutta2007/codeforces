#include <bits/stdc++.h>

using namespace std;
long long w=1e9, ba, bf, ja, jf, sx, sy, a, b, c, d, p;
int k(int x, int y) {
    cout.flush() << "? " << x << " " << y << "\n";
    cin >> p;
    return p;
}
int main()
{
    ba=k(1, 1), ja=k(w, 1), bf=k(1, w), sx=(w+1+ba-ja)/2, sy=(w+1+ba-bf)/2;
    a=1+k(sx, 1), b=1+k(1, sy), c=w-k(sx, w), d=w-k(w, sy);
    cout.flush() << "! " << b << " " << a << " " << d << " " << c << "\n";
    return 0;
}