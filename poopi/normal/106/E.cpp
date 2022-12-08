                                        /* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>
#define Inf 10000
#define Max 80

int n;
double x[110], y[110], z[110];
double xres, yres, zres;

double calc(double xt, double yt, double zt){
    double mx = 0;
    for(int i = 0; i < n; i++){
        double dx = x[i] - xt;
        double dy = y[i] - yt;
        double dz = z[i] - zt;
        double tmp = dx * dx + dy * dy + dz * dz;
        if(tmp > mx)
            mx = tmp;
    }
    return mx;
}

double funz(double xt, double yt){
    double zl = -Inf, zr = Inf;
    for(int i = 0; i < Max; i++){
        double m1 = (zl * 2 + zr) / 3.;
        double m2 = (zl + zr * 2) / 3.;
        double t1 = calc(xt, yt, m1);
        double t2 = calc(xt, yt, m2);
        if(t1 > t2)
            zl = m1;
        else zr = m2;
    }
    zres = zr;
    return calc(xt, yt, zr);
}

double funy(double xt){
    double yl = -Inf, yr = Inf;
    for(int i = 0; i < Max; i++){
        double m1 = (yl * 2 + yr) / 3.;
        double m2 = (yl + yr * 2) / 3.;
        double t1 = funz(xt, m1);
        double t2 = funz(xt, m2);
        if(t1 > t2)
            yl = m1;
        else yr = m2;
    }
    yres = yr;
    return funz(xt, yr);
}

int main(){
    string s1, s2;
    while(cin >> n){
        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i] >> z[i];
        double xl = -Inf, xr = Inf;
        for(int i = 0; i < Max; i++){
            double m1 = (xl * 2 + xr) / 3.;
            double m2 = (xl + xr * 2) / 3.;
            double t1 = funy(m1);
            double t2 = funy(m2);
            if(t1 > t2)
                xl = m1;
            else xr = m2;
            //cout << m1 << ' ' << m2 << ' ' << t1 << ' ' << t2 << endl;
        }
        xres = xl;
        funy(xres);
        funz(xres, yres);
        cout.precision(7);
        cout.setf(ios::fixed | ios::showpoint);
        cout << xres << ' ' << yres << ' ' << zres << endl;
    }
    return 0;
}