#include <bits/stdc++.h>

#define oo 1000000010
#define maxn 100010
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define filein "B.inp"
#define fileout "B.out"

using namespace std;

int n, dau, cuoi;
int a[maxn];

void nhap()
{
    Ri(n);
    FOR(i, 1, n) Ri(a[i]);
    a[n + 1] = oo;
}

void chuanbi()
{

}

int Timsl()
{
    dau = n + 1, cuoi = 1;
    FOR(i, 1, n) if(a[i] > a[i + 1])
    {
        dau = i;
        break;
    }
    int x= dau;
    while(a[x] > a[x + 1] && x <= n) x++;
    cuoi = x;
    if(x == n + 1) return 0;
    else return 1;
}

void xuli()
{
    int sl = Timsl();
    if(!sl) cout << "yes" << endl << 1 << " " << 1;
    else
    {
        reverse(a + dau, a + cuoi + 1);
        FOR(i, 1, n - 1) if(a[i] > a[i + 1])
        {
            cout << "no";
            exit(0);
        }
        cout << "yes" << endl << dau << " " << cuoi;
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