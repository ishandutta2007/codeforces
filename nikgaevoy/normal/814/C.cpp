#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <complex>

#include <cassert>

using namespace std;

const int inf = (int)1e9 + 7;
const double pi = 3.14159265358979323846;

int solve (const vector<int> &arr, int m)
{
    assert (arr.size () % 2 == 1);

    int sum = 0;

    for (int i = 1; i < arr.size (); i += 2)
        sum += arr[i];

    if (m >= sum)
    {
        for (int i = 0; i < arr.size (); i += 2)
            sum += arr[i];

        return sum;
    }

    int l = 0, r = 0;
    int curr = 0;

    while ((r % 2 == 0) || arr[r] <= m)
    {
        curr += arr[r];

        if (r % 2 == 1)
            m -= arr[r];

        r++;
    }

    int ans = curr + m;

    while (l + 1 < arr.size ())
    {
        curr -= arr[l] + arr[l + 1];
        m += arr[l + 1];

        l += 2;

        while (r < arr.size () && ((r % 2 == 0) || arr[r] <= m))
        {
            curr += arr[r];

            if (r % 2 == 1)
                m -= arr[r];

            r++;
        }

        ans = max (ans, curr + m);
    }

    return ans;
}

int main ()
{
    int q;
    string s;

    cin >> q >> s >> q;

    vector<vector<int>> blocks (27);

    for (char a = 'a'; a <= 'z'; a++)
    {
        if (s.front () != a)
            blocks[a - 'a'].push_back (0);
        for (int l = 0, r; l < s.size (); l = r)
        {
            for (r = l + 1; r < s.size () && ((s[l] == a) == (s[r] == a)); r++);

            blocks[a - 'a'].push_back (r - l);
        }
        if (s.back () != a)
            blocks[a - 'a'].push_back (0);
    }

    for (int i = 0; i < q; i++)
    {
        int m;
        char c;

        scanf ("%d %c", &m, &c);

        printf ("%d\n", solve (blocks[c - 'a'], m));
    }

    return 0;
}