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
#define maxn 1010
#define maxk 1000010

using namespace std;

ll n, m, k, p;
ll col[maxn], row[maxn], bestcol[maxk], bestrow[maxk];
priority_queue <ll> col1, row1;

int main()
{
   // freopen(filein, "r", stdin);
   // freopen(fileout, "w", stdout);
    int x;
    Ri(n), Ri(m), Ri(k), Ri(p);
    FOR(i, 1, n)
    FOR(j, 1, m)
    {
        Ri(x);
        col[j] += 1ll * x;
        row[i] += 1ll * x;
    }
    FOR(i, 1, n) row1.push(row[i]);
    FOR(i, 1, m) col1.push(col[i]);

    FOR(i, 1, k)
    {
        ll rm = row1.top();
        ll cm = col1.top();
        row1.pop(), col1.pop();
        bestrow[i] = bestrow[i - 1] + rm;
        row1.push(rm - 1ll * m * p);
        bestcol[i] = bestcol[i - 1] + cm;
        col1.push(cm - 1ll * n * p);
    }
    ll kq = -9876543212345678;
    FOR(i, 0, k) kq = max(kq, bestrow[i] + bestcol[k - i] - 1ll * (p * i) * (k - i));
    cout << kq;
    return 0;
}