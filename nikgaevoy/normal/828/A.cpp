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

    int n, a, b, c = 0;

    cin >> n >> a >> b;

    int res = 0;

    while (n-- > 0)
    {
        int t;

        cin >> t;

        if (t == 1)
            if (a > 0)
                a--;
            else if (b > 0)
            {
                c++;
                b--;
            }
            else if (c > 0)
                c--;
            else
                res++;
        else if (b > 0)
            b--;
        else
            res += 2;
    }

    cout << res << endl;

    return 0;
}