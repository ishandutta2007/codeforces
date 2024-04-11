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
#include <iomanip>
#include <iterator>

#include <cassert>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

mt19937 mt (736);

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, m;

    cin >> n >> m;

    vector<int> a (n), b (n);

    for (auto &it : a)
        cin >> it;
    for (auto &it : b)
        cin >> it;

    vector<int> reord (2 * n);

    for (int i = 1; i < b.size (); i++)
    {
        reord[2 * i - 1] = b[i];
        reord[2 * i] = a[i];
    }
    reord.front () = a.front ();
    reord.back () = b.front ();

    reverse (reord.begin (), reord.end ());

    double ans = m;

    for (auto it : reord)
    {
        it--;

        if (it <= 0)
        {
            cout << -1 << endl;

            return;
        }

        ans += ans / it;
    }

    cout << setprecision (20) << fixed << ans - m << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);

#ifdef LOCAL
    solve ();

    cout << "clock: " << clock () << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}