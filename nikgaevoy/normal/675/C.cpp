#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cstdio>

using namespace std;

const string filename = "tree40";
const bool interactive = true;

int main ()
{
    if (!interactive)
    {
        freopen ((filename + ".in").c_str (), "r", stdin);
        freopen ((filename + ".out").c_str (), "w", stdout);
    }

    int n;

    cin >> n;

    vector<int> banks (n);

    for (auto &it : banks)
        scanf ("%i", &it);

    unordered_map<long long, int> pos;
    pos.reserve (n);

    long long presum = 0;
    int best = 0;

    for (auto it : banks)
        best = max (best, ++pos[presum += it]);

    cout << n - best << endl;

    return 0;
}