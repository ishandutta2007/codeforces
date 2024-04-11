#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define ll long long
#define X first
#define Y second
#define push_back pb
#define filein "inp.txt"
#define fileout "out.txt"

#define oo
#define maxn 100010

using namespace std;

int n, m, d;
int a[maxn];
pair <int, int> b[maxn];
int trai[maxn], phai[maxn];

void chuanbi()
{
    FOR(i, 1, n) Ri(a[i]);
    trai[1] = 0;
    phai[n] = n + 1;
    FOR(i, 2, n)
    if(a[i] <= a[i - 1]) trai[i] = trai[i - 1];
    else trai[i] = i;
    FORN(i, n - 1, 1)
    if(a[i] <= a[i + 1]) phai[i] = phai[i + 1];
    else phai[i] = i;

}

int main()
{
    //freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);

    cin >> n >> m;
    chuanbi();
    int l, r;
    FOR(i, 1, m)
    {
        Ri(l), Ri(r);
        if(phai[l] >= trai[r]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}