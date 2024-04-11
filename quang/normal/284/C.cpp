#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define ll long long
#define make_pair mp
#define X first
#define Y second
#define push_back pb
#define filein "inp.txt"
#define fileout "out.txt"

#define oo
#define maxn 200010

using namespace std;

int n, loai, d = 1;
ll kq = 0;
int a[maxn], them[maxn];

int main()
{
    //freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);
    memset(a, 0, sizeof(a));
    memset(them, 0, sizeof(them));
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> loai;
        if(loai == 1)
        {
            int aa, xx;
            Ri(aa), Ri(xx);
            them[aa] += xx;
            kq += 1ll * aa * xx;
        }
        if(loai == 2)
        {
            int k;
            Ri(k);
            a[++d] = k;
            kq += 1ll * k;
        }
        if(loai == 3)
        {
            kq -= a[d] + them[d];
            them[d - 1] += them[d];
            them[d--] = 0;
        }
        printf("%0.6f\n", 1.0 * kq / d);
    }
}