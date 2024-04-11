#include <bits/stdc++.h>

#define oo
#define maxn
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define filein "C.inp"
#define fileout "C.out"

using namespace std;

int t;
long long n, k, d1, d2;

void nhap()
{
    Ri(t);
}

void chuanbi()
{

}

bool check(long long s1, long long s2)
{
    long long a[5];
    if((k - s1 + s2) % 3 == 0)
    {
        a[2] = (k - s1 + s2) / 3;
        a[1] = a[2] + s1;
        a[3] = a[2] - s2;
        if(a[1] < 0 || a[2] < 0 || a[3] < 0) return 0;
        long long gtmax = max(a[1], max(a[2], a[3]));
        long long conlai = n - k;
        conlai -= gtmax * 3 - a[1] - a[2] - a[3];
        if(conlai < 0 || conlai % 3) return 0;
        return 1;
    }
    return 0;
}

void xuli1()
{
    if(check(d1, d2) || check(d1, -d2) || check(-d1, d2) || check(-d1, -d2)) cout << "yes\n";
    else cout << "no\n";
}

void xuli()
{
    FOR(i, 1, t)
    {
        Rll(n), Rll(k), Rll(d1), Rll(d2);
        xuli1();
    }
}

void inkq()
{

}

int main()
{
    //freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);
    nhap();
    chuanbi();
    xuli();
    inkq();
    return 0;
}