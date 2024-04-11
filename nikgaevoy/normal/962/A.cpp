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
    int n;

    cin >> n;

    vector<int> arr (n);

    for (auto &it : arr)
        cin >> it;

    vector<long long> ps (arr.size () + 1);

    for (size_t i = 1; i < ps.size (); i++)
        ps[i] = ps[i - 1] + arr[i - 1];

    cout << lower_bound (ps.begin (), ps.end (), (ps.back () + 1) / 2) - ps.begin () << endl;
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