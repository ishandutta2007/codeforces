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

    vector<int> mult (m);

    for (auto &it : mult)
    {
        cout << 1 << endl << flush;

        cin >> it;

        if (it == 0)
            return;
    }

    int l = 1, r = n + 1;
    int pos = 0;

    while (l + 1 < r)
    {
        int t = (l + r) / 2;

        cout << t << endl << flush;

        int ans;
        cin >> ans;
        ans *= mult[pos++];
        pos %= mult.size ();

        if (ans == 0)
            return;

        (ans < 0 ? r : l) = t;
    }
}

int main ()
{
    //ios_base::sync_with_stdio (false);
    //cin.tie (nullptr);

#ifdef LOCAL
    solve ();

    cout << "clock: " << clock () << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}