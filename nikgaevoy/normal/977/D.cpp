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
#include <functional>
#include <iomanip>

#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

int val (long long n)
{
    int ans = 0;

    while (n % 2 == 0)
    {
        n /= 2;
        ans++;
    }

    while (n % 3 == 0)
    {
        n /= 3;
        ans--;
    }

    return ans;
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;

    cin >> n;

    vector<long long> arr (n);

    for (auto &it : arr)
        cin >> it;

    sort (arr.begin (), arr.end (), [](long long a, long long b) {
        return val (a) < val (b);
    });

    for (auto it : arr)
        cout << it << ' ';
    cout << endl;
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