#include <bits/stdc++.h>

#define oo 1ll * 1000000007
#define maxn
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define filein "B.inp"
#define fileout "B.out"

using namespace std;

long long x, y, n;

void nhap()
{
    cin >> x >> y >> n ;
}

void chuanbi()
{

}

long long Tinh(long long a)
{
    a = a + oo * 2;
    a %= oo;
    return a;
}

void xuli()
{
    n = (n - 1) % 6 + 1;
    if(n == 1) cout << Tinh(x);
    if(n == 2) cout << Tinh(y);
    if(n == 3) cout << Tinh(y - x);
    if(n == 4) cout << Tinh(-x);
    if(n == 5) cout << Tinh(-y);
    if(n == 6) cout << Tinh(x - y);
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