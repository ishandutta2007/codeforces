#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int inf = (int)1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (false);

    int n;

    cin >> n;

    vector<string> strs (n);
    vector<pair<int, int>> beg;

    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];

        int k;
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            int t;

            cin >> t;
            beg.push_back ({t - 1, i});
        }
    }

    sort (beg.begin (), beg.end ());

    string s;

    for (auto it : beg)
        if (s.size () < (it.first + strs[it.second].size ()))
        {
            while (s.size () < it.first)
                s += 'a';

            s += strs[it.second].substr (strs[it.second].size () + s.size () - (it.first + strs[it.second].size ()));
        }

    cout << s.c_str () << endl;

    return 0;
}