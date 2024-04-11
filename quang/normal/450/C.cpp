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
#define maxn

using namespace std;

ll n, m, k;

int main()
{
    //freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);
    Ri(n), Ri(m), Ri(k);
    if(m < n) swap(n, m);

    if(n + m - 2 < k) cout << -1;
    else
    if(k < n) cout << max(n * (m / (k + 1)), (n / (k + 1)) * m);
    else
        if(k < m) cout << n * (m / (k + 1));
        else cout << n / (k - m + 2);

    return 0;
}