#include <bits/stdc++.h>

using namespace std;
int x, y, z;
int a, b, c;
bool p=false;
int main()
{
    cin >> x >> y >> z >> a >> b >> c;
    if (x>a) {
        p=true;
    }
    b=a+b-x;
    if (y>b) {
        p=true;
    }
    c=c+b-y;
    if (z>c) {
        p=true;
    }
    if (p) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}