#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <random>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>

#include <cassert>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

mt19937 mt (736);

long long subsolve (const vector<pair<int, char>> &arr, int l, int r)
{
    assert (arr[l].second == 'P');
    assert (arr[r].second == 'P');

    int B = arr[l].first;
    int R = B;

    int ecoB = 0, ecoR = 0;

    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i].second != 'R')
        {
            ecoB = max (ecoB, arr[i].first - B);
            B = arr[i].first;
        }
        if (arr[i].second != 'B')
        {
            ecoR = max (ecoR, arr[i].first - R);
            R = arr[i].first;
        }
    }

    return min (2ll * (arr[r].first - arr[l].first),
                3ll * (arr[r].first - arr[l].first) - ecoR - ecoB);
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;

    cin >> n;

    vector<pair<int, char>> arr (n);

    for (auto &it : arr)
        cin >> it.first >> it.second;

    sort (arr.begin (), arr.end ());

    long long ans = 0;

    vector<int> P, B, R;

    for (int i = 0; i < arr.size (); i++)
        (arr[i].second == 'P' ? P : arr[i].second == 'B' ? B : R).push_back (i);

    for (int i = 1; i < P.size (); i++)
        ans += subsolve (arr, P[i - 1], P[i]);

    if (P.empty ())
    {
        if (!R.empty ())
            ans += arr[R.back ()].first - arr[R.front ()].first;
        if (!B.empty ())
            ans += arr[B.back ()].first - arr[B.front ()].first;
    }
    else
    {
        if (!R.empty ())
        {
            if (R.front () < P.front ())
                ans += arr[P.front ()].first - arr[R.front ()].first;
            if (R.back () > P.back ())
                ans += arr[R.back ()].first - arr[P.back ()].first;
        }
        if (!B.empty ())
        {
            if (B.front () < P.front ())
                ans += arr[P.front ()].first - arr[B.front ()].first;
            if (B.back () > P.back ())
                ans += arr[B.back ()].first - arr[P.back ()].first;
        }
    }

    cout << ans << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

#ifdef LOCAL
    solve ();

    cout << "clock: " << clock () << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}