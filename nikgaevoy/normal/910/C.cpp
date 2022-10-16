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
    int n;

    cin >> n;

    vector<pair<int, bool>> mult (10);
    unordered_set<int> leading;

    for (int i = 0; i < n; i++)
    {
        string str;

        cin >> str;

        mult[str.front () - 'a'].second = true;

        reverse (str.begin (), str.end ());

        int pt = 1;

        for (auto it : str)
        {
            mult[it - 'a'].first += pt;
            pt *= 10;
        }
    }

    sort (mult.begin (), mult.end (), greater<> ());

    int t = 0;

    while (mult[t].second)
        t++;

    rotate (mult.begin (), mult.begin () + t, mult.begin () + t + 1);

    int sum = 0;

    for (int i = 0; i < (int)mult.size (); i++)
        sum += mult[i].first * i;

    cout << sum << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

    solve ();

    return 0;
}