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

    vector<int> arr (101);

    for (int i = 0; i < m; i++)
    {
        int t;

        cin >> t;

        arr[t]++;
    }

    int l = 0, r = 101;

    while (l + 1 < r)
    {
        int t = (l + r) / 2;

        int sum = 0;

        for (auto it : arr)
            sum += it / t;

        (sum < n ? r : l) = t;
    }

    cout << l << endl;
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