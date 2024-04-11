#include <bits/stdc++.h>

using namespace std;
double n, k;
#define pi 3.14159265
int main()
{
    cin >> n >> k;
    double param, result;
    param = 60.0;
    /*result = cos ( param * pi / 180.0 );
    cout << result << endl;*/
    double x=0, y=10000;
    while(y-x>0.00000001) {
        double z=(x+y)/2;
        double p=2.0*(k+z)*(k+z);
        if (4.0*z*z>p-cos(360.0/n*pi/180.0)*(p)) {
            y=z;
        } else {
            x=z;
        }
    }
    cout.precision(8);
    cout << x << endl;
    return 0;
}