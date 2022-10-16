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

#include <cassert>
#include <cmath>

using namespace std;

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, d;

    cin >> n >> d;
    d++;

    string str;
    str.reserve (n);

    cin >> str;

    int cnt = 0;

    for (int l = 0, t; l < n - 1; cnt++, l = t)
    {
        t = -1;
        for (int r = l + 1; r < min (l + d, n); r++)
            if (str[r] == '1')
                t = r;

        if (t == -1)
        {
            cout << -1 << endl;

            return;
        }
    }

    cout << cnt << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

    solve ();

    return 0;
}