#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <random>
#include <limits>

#include <cassert>
#include <cmath>

using namespace std;

const int inf = (int)1e9 + 7;

template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

void bfs (const vector<vector<int>> &gr, vector<int> &dist, int st)
{
    queue<pair<int, int>> pq;
    pq.emplace (0, st);

    while (!pq.empty ())
    {
        auto t = pq.front ();
        pq.pop ();

        if (t.first < dist[t.second])
        {
            dist[t.second] = t.first;

            for (auto it : gr[t.second])
                pq.emplace (t.first + 1, it);
        }
    }
}

void dfs (const vector<vector<int>> &gr, vector<bool> &used, int v, vector<int> &ans)
{
    if (used[v])
        return;

    used[v] = true;

    ans.push_back (v);

    for (auto it : gr[v])
        dfs (gr, used, it, ans);
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;

    cin >> n;

    vector<vector<int>> gr (n);

    for (int i = 1; i < n; i++)
    {
        int a, b;

        cin >> a >> b;
        a--;
        b--;

        gr[a].push_back (b);
        gr[b].push_back (a);
    }

    vector<int> dist (gr.size (), numeric_limits<int>::max ());
    bfs (gr, dist, 0);

    int fe = max_element (dist.begin (), dist.end ()) - dist.begin ();

    fill (dist.begin (), dist.end (), numeric_limits<int>::max ());
    bfs (gr, dist, fe);

    int se = max_element (dist.begin (), dist.end ()) - dist.begin ();

    vector<int> tmp (dist.size (), numeric_limits<int>::max ());
    bfs (gr, tmp, se);

    vector<int> ord (n);

    for (int i = 0; i < ord.size (); i++)
        ord[i] = i;

    sort (ord.begin (), ord.end (), [&dist, &tmp](int a, int b) {
        return dist[a] + tmp[a] > dist[b] + tmp[b];
    });

    int diam = dist[se];
    long long ans = diam * (diam + 1ll) / 2;

    vector<bool> used (n);
    vector<pair<int, int>> del;
    del.reserve (n - 1);

    for (auto it : ord)
    {
        if (dist[it] + tmp[it] == diam)
            break;

        used[it] = true;

        del.emplace_back (dist[it] < tmp[it] ? se : fe, it);
        ans += max (dist[it], tmp[it]);
    }

    vector<int> q;

    dfs (gr, used, fe, q);
    q.pop_back ();

    for (auto it : q)
        del.emplace_back (se, it);

    cout << ans << endl;

    for (auto it : del)
        cout << it.first + 1 << ' ' << it.second + 1 << ' ' << it.second + 1 << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

    solve ();

    return 0;
}