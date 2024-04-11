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

#include <cassert>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

mt19937 mt (736);

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;

    cin >> n;
    vector<int> a (n), p (n);

    for (auto &it : a)
        cin >> it;
    for (auto &it : p)
        cin >> it;

    multiset<int> keys (p.begin (), p.end ());

    vector<int> ans;
    ans.reserve (n);

    for (auto it : a)
    {
        int cur = 0;

        for (int j = 30; j >= 0; j--)
        {
            int nxt = cur | ((1 << j) & it);

            auto wh = keys.lower_bound (nxt);

            if (wh != keys.end () && (~((1 << j) - 1) & *wh) == nxt)
                cur = nxt;
            else
                cur = nxt ^ (1 << j);
        }

        keys.erase (keys.find (cur));
        ans.push_back (cur ^ it);
    }

    for (auto it : ans)
        cout << it << ' ';
    cout << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

#ifdef LOCAL
    solve ();

    cout << "clock: " << clock () << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}