#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
const ld kek = 0.30150283239583161363;
int main()
{
  //  freopen("in.txt", "r", stdin)
    ld a, b, c;
    cin >> a >> b >> c;
    ld x = a * a * a / sqrt((ld)2) / (ld)2 / (ld)3;
    ld y = b * b * b / sqrt((ld)2) / (ld)3;
   // ld sum = 38.546168065709;
    cout.precision(20);
    cout << x + y + c * c * c * kek;
    return 0;
/*    ld func = (sum - x - y) / c / c / c;
    cout.precision(20);
    cout << func << " " << x + y;*/
    return 0; 
}