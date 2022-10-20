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
#define maxn 300010

using namespace std;

int n;
int a[maxn];
ll kq = 0ll;

int main()
{
    //freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);
    Ri(n);
    FOR(i, 1, n) Ri(a[i]);
    sort(a + 1, a + n + 1);
    FOR(i, 1, n) kq += 1ll * abs(a[i] - i);
    cout << kq;
    return 0;
}