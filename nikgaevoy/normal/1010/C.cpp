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

template<class T>
T gcd (T a, T b)
{
    return b == 0 ? a : gcd (b, a % b);
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, k;

    cin >> n >> k;

    int g = k;

    for (int i = 0; i < n; i++)
    {
        int t;

        cin >> t;

        g = gcd (g, t);
    }

    cout << k / g << endl;

    for (int i = 0; i < k / g; i++)
        cout << i * g << ' ';
    cout << endl;
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