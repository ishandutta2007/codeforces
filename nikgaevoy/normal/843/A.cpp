#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <complex>
#include <functional>
#include <queue>
#include <set>
#include <random>

#include <ctime>
#include <cmath>
#include <cstdlib>

#pragma warning (disable : 4018)
#pragma comment (linker, "/STACK:200000000")

using namespace std;

const int inf = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<int> arr (n);

    for (auto &it : arr)
        cin >> it;

    vector<pair<int, int>> ord (n);

    for (int i = 0; i < arr.size (); i++)
        ord[i] = {arr[i], i};

    sort (ord.begin (), ord.end ());

    for (int i = 0; i < ord.size (); i++)
        arr[ord[i].second] = i;

    vector<set<int>> ans;

    int start = 0;

    while (start < ord.size ())
    {
        if (arr[ord[start].second] == inf)
        {
            start++;
            continue;
        }

        ans.push_back (set<int> ());

        int pos = ord[start].second;

        while (!ans.back ().count (pos))
        {
            ans.back ().insert (pos);
            int nex = arr[pos];
            arr[pos] = inf;
            pos = nex;
        }
    }

    cout << ans.size () << endl;

    for (const auto &seq : ans)
    {
        cout << seq.size () << ' ';
        for (auto it : seq)
            cout << it + 1 << ' ';
        cout << endl;
    }

    return 0;
}