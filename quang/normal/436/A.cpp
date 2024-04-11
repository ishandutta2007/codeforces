#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 1000010
#define N 2010

using namespace std;

struct data
{
    int t, h, m;
    data(int _t = 0,int _h = 0,int _m = 0)
    {
        t = _t;
        h = _h;
        m = _m;
    }
} a[N];
int n, x, res = 0;
bool kt[N];

void Get(int tr, int u, int x)
{
    int kq = 0;
    for(int i = 1; i <= n; i++)
    if(!kt[i] && (a[i].t == 1 - tr) && a[i].h <= x && a[i].m > a[kq].m)
        kq = i;
    if(!kq)
    {
        res = max(res, u - 1);
        return;
    }
    kt[kq] = 1;
    Get(a[kq].t, u + 1, x + a[kq].m);
}

int main()
{
    //fi, fo;
    scanf("%d%d", &n, &x);
    for(int i = 1; i <= n; i++)
    {
        int t, h, m;
        scanf("%d%d%d", &t, &h, &m);
        a[i] = data(t, h, m);
    }
    a[0] = data(0, MAX, 0);
    memset(kt, 0 ,sizeof(kt));
    Get(0, 1, x);
    memset(kt, 0, sizeof(kt));
    Get(1, 1, x);
    cout << res;
    return 0;
}