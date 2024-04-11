#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define ll long long
#define X first
#define Y second
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY 1000000007
#define LIMIT 310

using namespace std;

int n, q, t, d;
ll sum  = 0;
int a[LIMIT], next[LIMIT], kt[LIMIT], gt[LIMIT];
int DP[100010];

int main()
{
    //filein, fileout;
    Ri(n), Ri(q), Ri(t);
    FOR(i, 1, n) Ri(a[i]);
    FOR(i, 1, q)
    {
        int u, v;
        Ri(u), Ri(v);
        next[u] = v;
        kt[v] = 1;
    }
    FOR(i, 1, n)
    if(!kt[i])
    {
        int s = 0, j = i;
        while(j)
        {
            sum += 1ll * s;
            s += a[j];
            gt[++d] = s;
            j = next[j];
        }
    }
    if(sum > 1ll * t || d != n)
    {
        cout << 0;
        return 0;
    }
    DP[sum] = 1;
    FOR(i, 1, n)
    FOR(j, gt[i], t)
    DP[j] = (DP[j] + DP[j - gt[i]]) % EXTREMELY;
    cout << DP[t];
    return 0;
}