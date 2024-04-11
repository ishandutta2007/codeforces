#include <bits/stdc++.h>
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY
#define LIMIT 100010

using namespace std;

int n, m, k;
int a[LIMIT], ll[LIMIT], rr[LIMIT], d[LIMIT];


struct data
{
    long long tree[LIMIT * 5];
    void Set(int l, int r, long long value, int node, int x, int y)
    {
          if(l <= x && y <= r)
          {
                tree[node] += value;
                return;
          }
          if(l > y || r < x) return;
          int mid = (x + y) >> 1;
          Set(l ,r, value, node * 2, x, mid);
          Set(l, r, value, node * 2 + 1, mid + 1, y);
          //tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    long long Get(int id, int node, int l, int r)
    {
        if(id > r || id < l) return 0ll;
        if(l == r) return tree[node];
        int mid = (l + r) >> 1;
        long long p1 = Get(id, node * 2, l, mid);
        long long p2 = Get(id, node * 2 + 1, mid + 1, r);
        return ( p1 + p2) + tree[node];
    }
} t1, t2;

int main()
{
    ios_base::sync_with_stdio(0);
    //filein, fileout;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> ll[i] >> rr[i] >> d[i];
    int x, y;
    for(int i = 1; i <= k; i++)
    {
        cin >> x >> y;
        t1.Set(x, y, 1ll, 1, 1, m);
    }
    for(int i = 1; i <= m; i++)
    {
        long long cnt = t1.Get(i, 1, 1, m);
        t2.Set(ll[i], rr[i], cnt * d[i], 1, 1, n);
    }
    for(int i = 1; i <= n; i++) cout << t2.Get(i, 1, 1, n) + a[i] << " ";
    return 0;
}