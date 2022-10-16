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
#include <ctime>
#include <cassert>

#include <conio.h>

using namespace std;

int main ()
{
    int n, f;

    cin >> n >> f;

    long long ans = 0;

    vector<int> days (n);

    for (auto &it : days)
    {
        int k, l;
        cin >> k >> l;

        ans += min (k, l);
        it = min (k, max (0, l - k));
    }

    sort (days.begin (), days.end (), greater<int> ());

    for (int i = 0; i < f; i++)
        ans += days[i];

    cout << ans << endl;

    return 0;
}