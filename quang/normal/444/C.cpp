#include <bits/stdc++.h>
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY
#define LIMIT 100010

using namespace std;

int n, m;
long long color[LIMIT * 5], sum[LIMIT * 5], delta[LIMIT * 5];

void Init(int node, int l, int r)
{
    if(l == r)
    {
        color[node] = l;
        return;
    }
    int m = (l + r) >> 1;
    Init(node * 2, l, m);
    Init(node * 2 + 1, m + 1, r);
}

void Paint(int l, int r, int node, int val)
{
    if(color[node])
    {
        delta[node] += 1ll * abs(val - color[node]);
        sum[node] += 1ll * abs(val - color[node]) * (r - l + 1);
        color[node] = 0;
        return;
    }
    if(l == r) return;
    int m = (l + r) >> 1;
    Paint(l, m, node * 2, val);
    Paint(m + 1, r, node * 2 + 1, val);
    sum[node] = sum[node * 2] + sum[node * 2 + 1] + delta[node] * (r - l + 1);
}

void Set(int x, int y, int val ,int node, int l, int r)
{
    if(r < x || y < l) return;
    if(x <= l && r <= y)
    {
        Paint(l, r, node, val);
        color[node] = val;
        return;
    }
    if(color[node] > 0)
    {
        color[node * 2] = color[node * 2 + 1] = color[node];
        color[node]  = 0;
    }
    int m = (l + r) >> 1;
    Set(x, y, val, node * 2, l, m);
    Set(x, y, val, node * 2 + 1, m + 1, r);
    sum[node] = sum[node * 2] + sum[node * 2 + 1] + delta[node] * (r - l + 1);
}

long long Get(int x, int y, int node, int l, int r)
{
    if(r < x || l > y) return 0;
    if(x <= l && r <= y) return sum[node];
    int m = (l + r) >> 1;
    long long p1 = Get(x, y, node * 2, l, m);
    long long p2 = Get(x, y, node * 2 + 1, m + 1, r);
    return p1 + p2 + delta[node] * max(0, min(y, r) - max(x, l) + 1);
}

int main()
{
    //filein, fileout;
    scanf("%d%d", &n, &m);
    Init(1, 1, n);
    while(m--)
    {
        int type, l, r, x;
        scanf("%d%d%d", &type, &l, &r);
        if(type == 1)
        {
            scanf("%d", &x);
            Set(l, r, x, 1, 1, n);
        }
        else printf("%I64d\n", Get(l, r, 1, 1, n));
    }
    return 0;
}