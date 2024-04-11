#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

#include <cstdio>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n, m;

    cin >> n >> m;

    while (m-- > 0)
    {
        bool good = false;
        cin >> n;

        unordered_set<int> was;
        was.reserve (n);

        while (n-- > 0)
        {
            int t;

            cin >> t;

            good |= was.count (-t);
            was.insert (t);
        }

        if (!good)
        {
            cout << "YES" << endl;

            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}