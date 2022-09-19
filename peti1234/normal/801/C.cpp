#include <bits/stdc++.h>

using namespace std;
long long n, p;
long long k, m;
long long f[100001];
long long e[100001];
double a, b;
bool lehet(double x)
{
    //cout << x << " ";
    double t=p*x;
    for (int i=1; i<=n; i++) {
        double y=(double)e[i]-(double)f[i]*x;
        //cout << y << " ";
        if (y<0) {
        t+=y;
        }
    }
    //cout << t << " ";
    if (t>=0) {
        //cout << "1" << endl;
        return true;
    }
    //cout << "0" << endl;
    return false;
}
int main()
{
    cin >> n >> p;
    for (int i=1; i<=n; i++) {
        cin >> f[i] >> e[i];
        k+=f[i];
        m+=e[i];
    }
    if (p>=k) {
        cout << -1 << endl;
        return 0;
    }
    a=0;
    b=(m/(k-p));
    b++;
    //cout << a << " " << b << endl;
    while ((b-a)/max(1.0, a)>0.0000001) {
        if (lehet((b+a)/2)) {
            a=(b+a)/2;
        }
        else {
        b=(b+a)/2;
        }
    }
    cout << (b+a)/2 << endl;
    return 0;
}