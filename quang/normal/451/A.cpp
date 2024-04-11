#include <bits/stdc++.h>

#define oo
#define maxn
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define filein "A.inp"
#define fileout "A.out"

using namespace std;

int n, m;

void nhap()
{
    Ri(n), Ri(m);
}

void chuanbi()
{

}

void xuli()
{
    if(min(n, m) % 2 == 0) cout << "Malvika";
    else cout << "Akshat";
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