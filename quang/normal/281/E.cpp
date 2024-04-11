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
#define maxn 100010

using namespace std;

int n, u, v;
vector <int> a[maxn];
double kq = 0ll;
bool kt[maxn];

void DFS(int u, int h)
{
    kt[u] = 1;
    kq += 1.0 / h;
    FOR(i, 0, (int)a[u].size() - 1)
    {
        int v = a[u][i];
        if(!kt[v]) DFS(v, h + 1);
    }
}

int main()
{
    //freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);
    Ri(n);
    FOR(i, 1, n - 1)
    {
        Ri(u), Ri(v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS(1, 1);
    printf("%0.6f", kq);
    return 0;
}