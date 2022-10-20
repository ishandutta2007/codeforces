#include <bits/stdc++.h>

#define oo
#define maxn 1010
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define filein "B.inp"
#define fileout "B.out"

using namespace std;

string s;
int k, n;
int gtmax = -1;
int a[30];

void nhap()
{
    cin >> s;
    cin >> k;
    n = s.size();
}

void chuanbi()
{
    FOR(i, 1, 26)
    {
        cin >> a[i];
        gtmax = max(gtmax, a[i]);
    }
}

void xuli()
{
    long long kq = 0;
    FOR(i, 0, n - 1)
        kq += 1ll * (i + 1) * a[s[i] - 96];
    FOR(i, n + 1, k + n) kq += 1ll * i * gtmax;
    cout << kq;
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