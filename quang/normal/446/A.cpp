#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <sstream>
#include <vector>
#define maxn 100010
#define oo 987654321
#define F first
#define S second
#define FOR(i, a, b) for(int i = (a); i <= (b);i++)
#define FORN(i, a, b) for(int i = (a); i >= (b);i--)
#define reset(a) memset(a, 0, sizeof(a))
#define mu(a) (1ll * 1 << a)
#define filein "C.inp"
#define fileout "C.out"

using namespace std;

int n, kq;
int a[maxn];
int l[maxn], r[maxn];

void nhap()
{
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    a[0] = -oo;
    a[n + 1] = oo;
}

void Timl()
{
    l[0] = 0;
    FOR(i, 1, n)
    if(a[i] > a[i - 1]) l[i] = l[i - 1] + 1;
    else l[i] = 1;

}

void Timr()
{
    r[n + 1] = 0;
    FORN(i, n, 1)
    if(a[i] < a[i + 1]) r[i] = r[i + 1] + 1;
    else r[i] = 1;
}

void xuli()
{
    Timl();
    Timr();
    FOR(i, 1, n)
    {
        if(a[i - 1] + 1 < a[i + 1]) kq = max(kq, l[i - 1] + 1 + r[i + 1]);
        else kq = max(kq, max(l[i - 1] + 1, r[i + 1] + 1));
    }
    if(kq > n) kq = n;
    cout << kq;
}

int main()
{
    //freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);
    nhap();
    xuli();
    return 0;
}