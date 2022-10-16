#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <cstdio>

using namespace std;

const int inf = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int q, l, m;
    long long b;

    cin >> b >> q >> l >> m;

    vector<int> tmp (m);

    for (auto &it : tmp)
        cin >> it;

    unordered_set<int> bad (tmp.begin (), tmp.end ());

    if (abs (b) > l)
        q = 2;
    else if (b == 0)
        q = 0;

    if (q == 0)
        if (bad.count (0))
            cout << !bad.count (b) << endl;
        else
            cout << "inf" << endl;
    else if (q == 1)
        cout << (bad.count (b) ? "0" : "inf") << endl;
    else if (q == -1)
        cout << (bad.count (b) && bad.count (-b) ? "0" : "inf") << endl;
    else
    {
        int cnt = 0;

        while (abs (b) <= l)
        {
            cnt += !bad.count (b);
            b *= q;
        }

        cout << cnt << endl;
    }

    return 0;
}