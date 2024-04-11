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

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;

    cin >> n;

    vector<int> arr (n);

    for (auto &it : arr)
        cin >> it;

    int prev = min_element (arr.begin (), arr.end ()) - arr.begin (), curr;
    int ans = numeric_limits<int>::max ();

    while (true)
    {
        curr = find (arr.begin () + prev + 1, arr.end (), arr[prev]) - arr.begin ();

        if (curr == arr.size ())
            break;

        ans = min (ans, curr - prev);
        prev = curr;
    }

    cout << ans << endl;
}

int main ()
{
    solve ();

    return 0;
}