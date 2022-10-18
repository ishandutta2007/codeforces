#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef double ld;
const int N = 3000001;

int d[N];
int a[N];
ll maxx[N], sum[N];

void buildtree(int v, int l, int r)
{
    if (r < l)
        return;
    if (l == r)
    {
        sum[v] = maxx[v] = a[l];
        return;
    }
    int mid = (r + l) / 2;
    buildtree(2 * v, l, mid);
    buildtree(2 * v + 1, mid + 1, r);
    sum[v] = sum[2 * v] + sum[2 * v + 1];
    maxx[v] = max(maxx[2 * v], maxx[2 * v + 1]);
}

ll tf(int v, int l, int r, int ql, int qr)
{
    if (r < l || ql > r || l > qr)
        return 0;
    if (ql <= l && r <= qr)
        return sum[v];
    int mid = (r + l) / 2;
    return tf(2 * v, l, mid, ql, qr) + tf(2 * v + 1, mid + 1, r, ql, qr);
}

void tu(int v, int l, int r, int ql, int qr)
{
    if (r < l || ql > r || l > qr || maxx[v] <= 2)
        return;
    if (l == r)
    {
        int t = maxx[v];
        sum[v] = maxx[v] = d[t];
        return;
    }
    int mid = (r + l) / 2;
    tu(2 * v, l, mid, ql, qr);
    tu(2 * v + 1, mid + 1, r, ql, qr);
    sum[v] = sum[2 * v] + sum[2 * v + 1];
    maxx[v] = max(maxx[2 * v], maxx[2 * v + 1]);
}

int main()
{
//    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            d[j]++;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    buildtree(1, 0, n - 1);
    for (int i = 0; i < m; i++)
    {
        int x, l, r;
        cin >> x >> l >> r;
        l--;
        r--;
        if (x == 1)
            tu(1, 0, n - 1, l, r);
        else
            cout << tf(1, 0, n - 1, l, r) << "\n";
    }
    return 0;
}