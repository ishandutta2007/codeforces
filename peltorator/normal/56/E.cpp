#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>

#define sz(a) (int)((a).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const int T = 2000001;

int tree[T];

void upd(int v, int l, int r, int q, int val)
{
    if (r <= l || r <= q || l > q)
    {
        return;
    }
    if (l + 1 == r)
    {
        tree[v] = val;
        return;
    }
    int mid = (r + l) / 2;
    upd(2 * v, l, mid, q, val);
    upd(2 * v + 1, mid, r, q, val);
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

int find(int v, int l, int r, int ql, int qr)
{
    if (r <= l || ql >= r || l >= qr)
    {
        return 1e9;
    }
    if (ql <= l && r <= qr)
    {
        return tree[v];
    }
    int mid = (r + l) / 2;
    return min(find(2 * v, l, mid, ql, qr), find(2 * v + 1, mid, r, ql, qr));
}

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    vector<pair<ll, pair<ll, int> > > q(n);
    for (int i = 0; i < n; i++)
    {
        cin >> q[i].first >> q[i].second.first;
        q[i].second.second = i;
    }
    sort(q.rbegin(), q.rend());
    vector<int> ans(n);
    for (int i = 0; i < q.size(); i++)
    {
        int l = -1, r = i;
        while (r - l > 1)
        {
            int mid = (r + l) / 2;
            if (q[mid].first - q[i].first < q[i].second.first)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        int x = min(r, find(1, 0, n, r, i));
        ans[q[i].second.second] = i - x + 1;
        upd(1, 0, n, i, x);
    }
    for (int i : ans)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    int T = 100;
    //cin >> T;
    for (int i = 0; i < T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cerr << "_______________________________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}