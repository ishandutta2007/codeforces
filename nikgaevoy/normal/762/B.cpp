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

    int a, b, c, m;

    cin >> a >> b >> c >> m;

    vector<int> usb, ps2;

    usb.reserve (m);
    ps2.reserve (m);

    for (int i = 0; i < m; i++)
    {
        int price;
        string type;

        cin >> price >> type;

        (type == "USB" ? usb : ps2).push_back (price);
    }

    sort (usb.begin (), usb.end ());
    sort (ps2.begin (), ps2.end ());

    long long sum = 0;

    for (int i = 0; i < min (a, (int)usb.size ()); i++)
        sum += usb[i];
    for (int i = 0; i < min (b, (int)ps2.size ()); i++)
        sum += ps2[i];

    vector<int> oth;
    oth.reserve (m);

    for (int i = a; i < usb.size (); i++)
        oth.push_back (usb[i]);
    for (int i = b; i < ps2.size (); i++)
        oth.push_back (ps2[i]);

    sort (oth.begin (), oth.end ());

    for (int i = 0; i < min (c, (int) oth.size ()); i++)
        sum += oth[i];

    cout << min ((int)usb.size (), a) + min ((int)ps2.size(), b) + min ((int)oth.size (), c) << ' ' << sum << endl;

    return 0;
}