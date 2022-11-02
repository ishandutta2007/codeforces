#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair <int, pair <int, int> > piii;
const int N = 2e5;

int a[N], p[N], number[N];
vector <piii> x;

int find_parent(int x)
{
    if (p[x] != x) p[x] = find_parent(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        x.push_back(make_pair(min(a[u], a[v]), make_pair(u, v)));
    }
    sort(x.begin(), x.end());
    ll ans = 0;
    for (int i = 1; i <= n; i++) p[i] = i, number[i] = 1;
    for (int i = x.size() - 1; i >= 0; i--)
    {
        int u = x[i].second.first, v = x[i].second.second;
        int p1 = find_parent(u), p2 = find_parent(v);
        if (p1 == p2) continue;
        ans += 1LL * number[p1] * number[p2] * min(a[u], a[v]);
        if (number[p1] < number[p2]) swap(p1, p2);
        p[p2] = p1;
        number[p1] += number[p2];
    }
    double res = 2 * ans;
    res /= 1LL * n * (n - 1);
    printf("%.6lf\n", res);
    return 0;
}