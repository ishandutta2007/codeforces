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
    int n, k;

    cin >> n >> k;

    string str;

    cin >> str;

    sort (str.begin (), str.end ());
    str.resize (unique (str.begin (), str.end ()) - str.begin ());

    if (str.size () < k)
    {
        cout << -1 << endl;

        return;
    }

    for (int i = 1; i < k; i++)
    {
        if (str[i] - str[i - 1] < 2)
            str.erase (str.begin () + i);

        if (str.size () < k)
        {
            cout << -1 << endl;

            return;
        }
    }

    str.resize (k);

    int sum = k;

    for (char c : str)
        sum += c - 'a';

    cout << sum << endl;
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