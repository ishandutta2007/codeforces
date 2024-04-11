#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <cstdio>

#define REL 0

#if REL
#include <conio.h>
#endif

using namespace std;
const int inf = int (1e9);

int main ()
{
    ios_base::sync_with_stdio (false);

    int n;
    cin >> n;
    vector<int> roads (1 << n + 1);

    for (int i = 2; i < roads.size (); i++)
        cin >> roads[i];

    long long r = 0;

    for (int i = roads.size () - 2; i > 1; i -= 2)
    {
        roads[i] += 2 * i < roads.size () ? roads[2 * i] : 0;
        roads[i + 1] += 2 * i + 2 < roads.size () ? roads[2 * i + 2] : 0;

        if (roads[i] < roads[i + 1])
            swap (roads[i], roads[i + 1]);

        r += roads[i] - roads[i + 1];
    }

    cout << r;

#if REL
    _getch ();
#endif

    return 0;
}