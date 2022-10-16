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

    map<int, int> arr;

    for (int i = 0; i < n; i++)
    {
        int it;

        cin >> it;

        arr[it]++;
    }

    int cnt = 0;

    for (auto it = arr.begin (); it != arr.end (); ++it)
    {
        auto nxt = it;
        nxt++;

        if (nxt == arr.end () || nxt->first - it->first > k)
            cnt += it->second;
    }

    cout << cnt << endl;
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