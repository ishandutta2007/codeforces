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

#include <cassert>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

mt19937 mt (736);

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, a, b;

    cin >> n >> a >> b;

    string str;

    cin >> str;

    int ans = 0;

    if (a < b)
        swap (a, b);

    for (auto it : str)
        if (it == '.')
        {
            if (a > 0)
            {
                a--;
                ans++;
            }

            swap (a, b);
        }
        else
        {
            assert (it == '*');

            if (a < b)
                swap (a, b);
        }

    cout << ans << endl;
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