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
    int n, k;

    cin >> n >> k;

    vector<int> links (n);

    for (auto &it : links)
    {
        cin >> it;
        it--;
    }

    vector<int> ans (links.size ());

    for (int i = 0; i < (int)ans.size (); i++)
        if (links[i] == -1)
            ans[i] = min (k, i) + 1 + min (k, (int)ans.size () - 1 - i);
        else
        {
            ans[i] = 1 + min (k, (int)ans.size () - 1 - i);

            ans[i] += ans[links[i]] - min (k, (int)ans.size () - 1 - links[i]);
            ans[i] += min (i - links[i] - 1, 2 * k);
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

    solve ();

    return 0;
}