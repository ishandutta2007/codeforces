#include <bits/stdc++.h>

#define oo
#define maxn 500010
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define filein "D.inp"
#define fileout "D.out"

using namespace std;

int n, m ;
long long k;

void nhap()
{
    scanf("%d%d%I64d", &n, &m, &k);
}

void chuanbi()
{

}

void xuli()
{
    long long  l = 0;
    long long  r = 1ll * n * m + 1;
    while(r - l > 1)
    {
        long long g = (l + r) / 2;
        long long sl = 0;
        FOR(i, 1, n) sl += min((g - 1) / i, 1ll * m);
        if(sl < k) l = g;
        else r = g;
    }
    printf("%I64d", l);
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