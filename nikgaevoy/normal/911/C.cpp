#include <iostream>
#include <fstream>
#include <vector>
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

#include <cassert>
#include <cmath>

using namespace std;

template<class T>
T gcd (T a, T b)
{
    return b ? gcd (b, a % b) : a;
}

template<class T>
T lcm (T a, T b)
{
    return a * b / gcd (a, b);
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    vector<int> k (3);

    for (auto &it : k)
        cin >> it;

    sort (k.begin (), k.end ());

    if (k[2] < 30)
    {
        int l = lcm (k[0], lcm (k[1], k[2]));

        for (int i = 0; i < l; i++)
            for (int j = 0; j < l; j++)
            {
                bool good = true;

                for (int r = 0; good && r < l; r++)
                    good &= r % k[0] == 0 || r % k[1] == i || r % k[2] == j;

                if (good)
                {
                    cout << "YES" << endl;

                    return;
                }
            }

        cout << "NO" << endl;
    }
    else if (k[0] == 1 || k[1] == 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main ()
{
    solve ();

    return 0;
}