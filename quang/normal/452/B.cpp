#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define ll long long
#define X first
#define Y second
#define filein "inp.txt"
#define fileout "out.txt"

#define oo
#define maxn

using namespace std;

struct toado
{
    int x, y;
    toado(){};
    toado(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

struct data
{
    toado p1, p2, p3, p4;
    double kc;
    data(){};
    data(toado _p1, toado _p2, toado _p3, toado _p4, double _kc)
    {
        p1 = _p1;
        p2 = _p2;
        p3 = _p3;
        p4 = _p4;
        kc = _kc;
    }
};

int n, m;

double Dis(toado a, toado b)
{
    long long xx = (1ll * a.x - b.x) * (a.x - b.x);
    long long yy = (1ll * a.y - b.y) * (a.y - b.y);
    return sqrt(1.0 * xx + yy);
}

int main()
{
    //freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);
    Ri(n), Ri(m);
    if(!n)
    {
        cout << 0 << " " << 1<< endl;
        cout << 0 << " " << m << endl;
        cout << 0 << " " << 0 << endl;
        cout << 0 << " " << m - 1 << endl;
        return 0;
    }
    if(!m)
    {
        cout << 1 << " " << 0<< endl;
        cout << n << " " << 0 << endl;
        cout << 0 << " " << 0 << endl;
        cout << n - 1 << " " << 0 << endl;
        return 0;
    }
    double cheo = Dis(toado(0, 0), toado(n, m));
    data kq;
    if(n < m)
    {
        kq = data( toado(0,0), toado(n, m), toado(n, 0), toado(0, m), cheo * 2 + 1.0 * m);
        double cheo2 = Dis( toado(0,0), toado(n - 1, m));
        if(kq.kc < cheo2 * 2 + cheo) kq = data( toado(n - 1, m), toado(0, 0), toado(n, m), toado(1, 0), cheo2 * 2 + cheo);
    }
    else
    {
        kq = data( toado(0, 0), toado(n, m), toado(0, m), toado(n, 0), cheo * 2 + 1.0 * n);
        double cheo2 = Dis(toado(0, 0), toado(n, m - 1));
        if(kq.kc < cheo2 * 2 + cheo) kq = data( toado(0, 1), toado(n, m), toado(0, 0), toado(n, m - 1), cheo2 * 2 + cheo);
    }
    cout << kq.p1.x << " " << kq.p1.y << endl;
    cout << kq.p2.x << " " << kq.p2.y << endl;
    cout << kq.p3.x << " " << kq.p3.y << endl;
    cout << kq.p4.x << " " << kq.p4.y << endl;
    return 0;
}