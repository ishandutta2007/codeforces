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

int cntbits (int n)
{
    return n ? cntbits (n & (n - 1)) + 1 : 0;
}

bool check (string str)
{
    if (str.empty () || str.front () == '0')
        return false;

    int n = stoi (str);

    int s = (int)sqrt (n);

    return s * s == n;
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    string str;

    cin >> str;

    int ans = numeric_limits<int>::max ();

    for (int i = 0; i < (1 << str.size ()); i++)
    {
        string q;

        for (int j = 0; j < str.size (); j++)
            if (i & (1 << j))
                q += str[j];

        if (check (q))
            ans = min (ans, (int)str.size () - cntbits (i));
    }

    cout << (ans == numeric_limits<int>::max () ? -1 : ans) << endl;
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