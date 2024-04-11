#include <bits/stdc++.h>

#define oo
#define maxn 5050
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define filein "C.inp"
#define fileout "C.out"

using namespace std;

int n;
int a[maxn];

void nhap()
{
    Ri(n);
    FOR(i, 1, n) Ri(a[i]);
}

void chuanbi()
{

}

int sl(int l, int r, int cur)
{
    if(l > r) return 0;
    int s = 0, gtmin = *min_element(a + l, a + r + 1);
    int last = l;
    s +=gtmin - cur;
    FOR(i, l, r)
    if(a[i] == gtmin)
    {
        s += sl(last, i - 1, gtmin);
        last = i + 1;
    }
    s += sl(last, r, gtmin);
    return min(s, r - l + 1);
}

void xuli()
{
    cout << sl(1, n, 0);
}

void inkq()
{

}

int main()
{
   // freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);
    nhap();
    chuanbi();
    xuli();
    inkq();
    return 0;
}