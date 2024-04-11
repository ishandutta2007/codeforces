#include <iostream>
#include <fstream>
#include <vector>
#include <array>
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
#include <string>
#include <sstream>
#include <functional>
#include <iomanip>

#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

mt19937 mt (736);

template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

vector<pair<string, int>> bfs (const string &s, int ver,
         map<pair<string, int>, vector<pair<string, int>>> &Vaja)
{
    priority_queue<pair<int, pair<int, string>>> pq;
    set<string> used;
    vector<pair<string, int>> ans;

    pq.emplace (0, pair<int, string>{ver, s});

    while (!pq.empty ())
    {
        auto t = pq.top ();
        pq.pop ();

        if (!used.count (t.second.second))
        {
            used.insert (t.second.second);

            ans.emplace_back (t.second.second, t.second.first);

            for (const auto &it : Vaja[ans.back ()])
                pq.emplace (t.first - 1, pair<int, string>{it.second, it.first});
        }
    }

    return ans;
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;

    cin >> n;

    map<pair<string, int>, vector<pair<string, int>>> Vaja;

    pair<string, int> root;

    for (int i = 0; i < n; i++)
    {
        string str;
        int ver;

        cin >> str >> ver;

        if (i == 0)
            root = {str, ver};

        int q;

        cin >> q;

        for (int j = 0; j < q; j++)
        {
            string tmp;
            int v;

            cin >> tmp >> v;

            Vaja[{str, ver}].emplace_back (tmp, v);
        }
    }

    auto ans = bfs (root.first, root.second, Vaja);

    ans.erase (ans.begin ());

    sort (ans.begin (), ans.end ());

    cout << ans.size () << endl;

    for (auto it : ans)
        cout << it.first << ' ' << it.second << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

    solve ();

#ifdef LOCAL
    cout << "clock: " << clock () << endl;
#endif // LOCAL

    return 0;
}