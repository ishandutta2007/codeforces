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

template<class T>
T gcd (T a, T b)
{
    return b ? gcd (b, a % b) : a;
}

template<class T>
T lcm (T a, T b)
{
    return a * b / gcd (a, b);
}


int bubble (vector<int> &arr)
{
    int cnt = 0;

    for (int i = 0; i < arr.size (); i++)
        for (int j = 1; j < arr.size (); j++)
            if (arr[j] < arr[j - 1])
            {
                swap (arr[j], arr[j - 1]);
                cnt++;
            }

    return cnt;
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;

    cin >> n;

    vector<int> arr (n);

    for (auto &it : arr)
        cin >> it;

    bool odd = bubble (arr) & 1;

    int q;

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int l, r;

        cin >> l >> r;
        l--;
        r -= l;

        odd ^= (r * (r - 1) / 2) & 1;

        cout << (odd ? "odd" : "even") << endl;
    }
}

int main ()
{
    solve ();

    return 0;
}