#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <cstdio>
#include <ctime>
#include <cassert>

using namespace std;

const int inf = int (1e9) + 7;

void Dijkstra (const vector<vector<int>> &arr, const vector<int> &me, vector<long long> &dist)
{
    vector<bool> used (arr.size ());

    for (int i = 0; i < used.size (); i++)
        used[i] = !me[i];

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    for (int i = 0; i < me.size (); i++)
        q.push ({2 * me[i], i});

    for (int i = 0; i < me.size (); i++)
        if (me[i] == 0)
            for (int j = 0; j < arr.size (); j++)
                q.push ({arr[i][j], j});

    while (!q.empty ())
    {
        auto it = q.top ();
        q.pop ();

        if (!used[it.second])
        {
            used[it.second] = true;

            dist[it.second] = it.first;

            for (int i = 0; i < arr[it.second].size (); i++)
                if (!used[i])
                    q.push ({it.first + arr[it.second][i], i});
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<vector<int>> arr (n, vector<int> (n, inf));

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            cin >> arr[i][j];
            arr[j][i] = arr[i][j];
        }

    vector<int> me (n);

    for (int i = 0; i < n; i++)
        me[i] = *min_element (arr[i].begin (), arr[i].end ());

    int shift = *min_element (me.begin (), me.end ());

    for (auto &it : me)
        it -= shift;

    for (auto &row : arr)
        for (auto &it : row)
            it -= shift;

    vector<long long> dist (n);

    Dijkstra (arr, me, dist);

    for (auto it : dist)
        cout << it + shift * (long long)(n - 1) << endl;

    return 0;
}