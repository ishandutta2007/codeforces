#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>

#include <cassert>

using namespace std;

const int inf = (int)1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    string s;

    cin >> s;

    vector<int> a (s.size () + 1), b (s.size () + 1);

    for (size_t i = 1; i < a.size (); i++)
    {
        a[i] = a[i - 1];
        b[i] = b[i - 1];

        if (s[i - 1] == 'a')
            a[i]++;
        else
        {
            assert (s[i - 1] == 'b');
            b[i]++;
        }
    }

    int ans = 0;

    for (size_t i = 0; i <= s.size (); i++)
        for (size_t j = i; j <= s.size (); j++)
            ans = max (ans, a[i] + (b[j] - b[i]) + (a.back () - a[j]));

    cout << ans << endl;

    return 0;
}