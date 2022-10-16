#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

const int inf = (int)1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (false);

    string a, b;

    cin >> a >> b;

    unordered_map<char, char> m;
    m.reserve (26 * 2 + 10);

    for (char c = '0'; c <= '9'; c++)
        m[c] = c;

    for (int i = 0; i < a.size (); i++)
    {
        m[a[i]] = b[i];
        m[a[i] + ('A' - 'a')] = b[i] + ('A' - 'a');
    }

    string t;

    cin >> t;

    for (auto &it : t)
        it = m[it];

    cout << t << endl;

    return 0;
}