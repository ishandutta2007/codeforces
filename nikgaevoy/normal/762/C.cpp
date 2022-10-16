#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <random>
#include <complex>
#include <iomanip>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

#pragma comment(linker,"/STACK:200000000")

using namespace std;

const double pi = 3.14159265358979323846;
const int inf = int (1e9) + 7;

int main ()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);

    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    string a, b;

    cin >> a >> b;

    vector<size_t> pr (b.size (), a.find (b.front ())), su (b.size (), a.rfind (b.back ()));

    for (int i = 1; i < b.size (); i++)
        pr[i] = a.find (b[i], pr[i - 1] + 1);
    for (int i = b.size () - 2; i >= 0; i--)
        su[i] = su[i + 1] == string::npos || su[i + 1] == 0 ? string::npos : a.rfind (b[i], su[i + 1] - 1);

    int l = 0, r = find_if_not (su.begin (), su.end (), [](size_t t) { return t == string::npos; }) - su.begin ();

    int bl = -1, br = r;

    for (; l < pr.size () && pr[l] != string::npos; l++)
    {
        while (r <= l || r < su.size () && su[r] <= pr[l])
            r++;

        if (r - l < br - bl)
        {
            bl = l;
            br = r;
        }
    }

    string ans = b.substr (0, bl + 1) + b.substr (br);

    if (ans.empty ())
        cout << '-' << endl;
    else
        cout << ans.c_str () << endl;

    return 0;
}