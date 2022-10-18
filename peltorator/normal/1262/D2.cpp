#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define char unsigned char

using namespace std;
using namespace __gnu_pbds;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
Tree;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<pair<int, int> > q(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        q[i] = {x, -i};
    }
    sort(q.rbegin(), q.rend());
    int m;
    cin >> m;
    vector<int> ans(m);
    vector<pair<int, pair<int, int> > > que;
    for (int i = 0; i < m; i++)
    {
        int k, pos;
        cin >> k >> pos;
        que.push_back({k, {pos - 1, i}});
//        cout << q[pos - 1].first << '\n';
    }
    sort(que.begin(), que.end());
    Tree t;
    int cur = 0;
    for (auto it : que)
    {
        while (cur < it.first)
        {
            t.insert(-q[cur++].second);
        }
        ans[it.second.second] = *t.find_by_order(it.second.first);
    }
    for (int i : ans)
        cout << a[i] << ' ';
    cout << '\n';
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    // cin >> TET;
    for (int i = 1; i <= TET; i++)
    {
        if (solve())
            break;
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}