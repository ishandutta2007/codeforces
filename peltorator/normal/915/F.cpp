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

const int N = 1000001;

ll a[N];
int n;
ll pr[N], sz[N];
vector<pair<ll, ll> > q, ed;

int fs(int v)
{
    return (v == pr[v] ? v : (pr[v] = fs(pr[v])));
}

ll f()
{
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        sz[i] = 1, pr[i] = i;
    for (int i = 0; i < q.size(); i++)
    {
        ll w = q[i].first;
        int v = ed[q[i].second].first;
        int u = ed[q[i].second].second;
        v = fs(v);
        u = fs(u);
        ans += sz[v] * sz[u] * w;
        if (sz[v] < sz[u])
            swap(v, u);
        sz[v] += sz[u];
        pr[u] = v;
    }
    return ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        q.push_back({max(a[x], a[y]), i});
        ed.push_back({x, y});
    }
    sort(q.begin(), q.end());
    ll cur = f();
    q.clear();
    for (int i = 0; i < n - 1; i++)
        q.push_back({min(a[ed[i].first], a[ed[i].second]), i});
    sort(q.rbegin(), q.rend());
    ll t = f();
    cout << cur - t;
    return 0;
}