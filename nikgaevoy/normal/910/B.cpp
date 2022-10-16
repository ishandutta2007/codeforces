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

#include <cassert>
#include <cmath>

using namespace std;

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, a, b;

    cin >> n >> a >> b;

    vector<int> arr = {a, a, a, a, b, b};

    sort (arr.begin (), arr.end ());

    auto cnt = numeric_limits<int>::max ();

    do
    {
        int cur = 0, piece = 0;

        for (auto it : arr)
        {
            if (piece < it)
            {
                cur++;
                piece = n;
            }

            piece -= it;
        }

        cnt = min (cnt, cur);
    } while (next_permutation (arr.begin (), arr.end ()));

    cout << cnt << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

    solve ();

    return 0;
}