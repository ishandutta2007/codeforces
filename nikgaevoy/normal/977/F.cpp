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

vector<int> lis (const vector<int> &arr)
{
    vector<int> par (arr.size (), -1);
    unordered_map<int, pair<int, int>> dp;
    dp.reserve (arr.size ());

    for (int i = 0; i < arr.size (); i++)
    {
        auto it = arr[i];

        int l = 1;

        if (dp.count (it - 1))
        {
            par[i] = dp[it - 1].second;
            l += dp[it - 1].first;
        }

        dp[it] = {l, i};
    }

    int st = 0;

    dp[st];

    for (auto it : dp)
        if (it.second > dp[st])
            st = it.first;

    st = dp[st].second;

    vector<int> ans;

    while (st != -1)
    {
        ans.push_back (st);
        st = par[st];
    }

    reverse (ans.begin (), ans.end ());

    return ans;
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;

    cin >> n;

    vector<int> arr (n);

    for (auto &it : arr)
        cin >> it;

    auto ans = lis (arr);

    cout << ans.size () << endl;

    for (auto it : ans)
        cout << it + 1 << ' ';
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