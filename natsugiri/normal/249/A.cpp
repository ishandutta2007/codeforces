#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<complex>
#include<cmath>
using namespace std;


typedef long long LL;
typedef complex<double> P;
const double PI = acos(-1);
double Y1, y2, yw, xb, yb, r;
double yt, y1p, y2p, m;

int main() {
    cin>>Y1>>y2>>yw>>xb>>yb>>r;
    P b(xb, yb), z1, z2;
    y1p=2*(yw-r)-Y1;
    y2p=2*(yw-r)-y2;
    yt=y1p-r;
    double theta = atan2(yb-yt, xb);
    z1=b-polar(r, PI/2+theta);
    if (arg(z1-P(0, y2p)) >= arg(b-P(0, yt))) 
	//cout<< ((yw-r)*xb - yt*xb) / (yb-yt) <<endl;
	printf("%.20f\n", ((yw-r)*xb - yt*xb) / (yb-yt));
    else puts("-1");

    return 0;
}