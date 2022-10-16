#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <random>

#include <cassert>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<bool> used (n);
    int rm = used.size () - 1;

    for (int i = 0; i < n; i++)
    {
        cout << rm + 2 - (n - i) << ' ';

        int t;

        cin >> t;

        used[--t] = true;

        while (rm >= 0 && used[rm])
            rm--;
    }

    cout << 1 << endl;

    return 0;
}