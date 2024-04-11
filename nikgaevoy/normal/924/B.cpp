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
    int n, U;

    cin >> n >> U;

    vector<int> E (n);

    for (auto &it : E)
        cin >> it;

    double ans = -1;

    for (int l = 0, r = 0; l < E.size (); l++)
    {
        while (r < E.size () && E[r] <= E[l] + U)
            r++;

        if (r > l + 2)
            ans = max (ans, (E[r - 1] - E[l + 1]) / (double)(E[r - 1] - E[l]));
    }

    if (ans < 0)
    {
        cout << -1 << endl;

        return;
    }

    cout.precision (20);
    cout << fixed << ans << endl;
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