#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;
typedef double ld;

const int N = 1000000;
const ll INF = 1e9 + 7;

ll nod(ll x, ll y)
{
    return (x ? nod(y % x, x) : y);
}

ll nok(ll x, ll y)
{
    if (x > y)
        swap(x, y);
    return nod(x, y);
    return min(INF, x / nod(x, y) * y);
}

ll tree[N], a[N];

void buildtree(int v, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        tree[v] = a[l];
        return;
    }
    int mid = (r + l) / 2;
    buildtree(2 * v, l, mid);
    buildtree(2 * v + 1, mid + 1, r);
    tree[v] = nok(tree[2 * v], tree[2 * v + 1]);
}

ll find(int v, int l, int r, int ql, int qr)
{
    if (r < l || qr < l || r < ql)
        return 0;
    if (ql <= l && r <= qr)
        return tree[v];
    int mid = (r + l) / 2;
    return nok(find(2 * v, l, mid, ql, qr), find(2 * v + 1, mid + 1, r, ql, qr));
}

int l[N], r[N], best[N], ans[N], was[N];

vector<pair<int, pair<int, int> > > q;

map<int, int> p;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
  //  freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], q.push_back({i, {0, a[i]}});;
    int qq;
    cin >> qq;
    buildtree(1, 1, n);
    for (int i = 0; i < qq; i++)
    {
        cin >> l[i] >> r[i];
        best[i] = find(1, 1, n, l[i], r[i]);
        q.push_back({l[i], {-1, i}});
        q.push_back({r[i], {1, i}});
    }
    sort(q.begin(), q.end());
    for (int i = 0; i < q.size(); i++)
    {
        if (q[i].second.first == -1)
            was[q[i].second.second] = p[best[q[i].second.second]];
        else if (q[i].second.first == 1)
            ans[q[i].second.second] = p[best[q[i].second.second]] - was[q[i].second.second];
        else
            p[q[i].second.second]++;
    }
    for (int i = 0; i < qq; i++)
        cout << r[i] - l[i] + 1 - ans[i] << "\n";
    return 0;
}