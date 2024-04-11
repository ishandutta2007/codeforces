#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <cstdio>
#include <ctime>
#include <cassert>

using namespace std;

const int inf = int (1e9) + 7;

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<int> arr (n);

    for (auto &it : arr)
    {
        int t;

        cin >> it >> t;

        if (it != t)
        {
            cout << "rated" << endl;

            return 0;
        }
    }

    cout << (is_sorted (arr.begin (), arr.end (), greater<int> ()) ? "maybe" : "unrated") << endl;

    return 0;
}