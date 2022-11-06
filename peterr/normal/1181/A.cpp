#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x, y, z;
    cin >> x >> y >> z;
    long long cocos = (x + y) / z;
    long long debt = 0;
    if (x % z + y % z >= z)
        debt = min((z - (x % z)) % z, (z - (y % z)) % z);
    cout << cocos << " " << debt;
    return 0;
}