#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int inf = (int)1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (false);

    int n, k, p;

    cin >> n >> k >> p;

    vector<int> people (n), keys (k);

    for (auto &it : people)
        cin >> it;
    for (auto &it : keys)
        cin >> it;

    sort (people.begin (), people.end ());
    sort (keys.begin (), keys.end ());

    int ans = numeric_limits<int>::max ();

    for (int i = 0; i <= keys.size () - people.size (); i++)
    {
        int tm = 0;

        for (int j = 0; j < people.size (); j++)
            tm = max (tm, abs (people[j] - keys[j + i]) + abs (keys[j + i] - p));

        ans = min (ans, tm);
    }

    cout << ans << endl;

    return 0;
}