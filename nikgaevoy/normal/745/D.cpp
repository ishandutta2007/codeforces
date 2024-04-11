#pragma comment(linker,"/STACK:200000000")

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include <random>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>

using namespace std;

const string filename = "tree40";
bool interactive = true;
const int inf = 1e9 + 7;

vector<int> ans;

void foo (const vector<int> &arr)
{
    cout << arr.size () << endl;
    for (auto it : arr)
        cout << it + 1 << ' ';
    cout << endl;
    cout.flush ();

    vector<int> tmp (ans.size ());

    for (auto &it : tmp)
        cin >> it;

    int pos = 0;

    for (int i = 0; i < tmp.size (); i++)
        if (pos < arr.size () && arr[pos] == i)
            pos++;
        else
            ans[i] = min (ans[i], tmp[i]);
}

void foo (int n)
{
    vector<int> g, b;

    for (int i = 0; (1 << i) < n; i++)
    {
        for (int j = 0; j < n; j++)
            ((j & (1 << i)) == 0 ? g : b).push_back (j);

        foo (g);
        foo (b);

        g.clear ();
        b.clear ();
    }
}

int main ()
{
    if (!interactive)
    {
        freopen ((filename + ".in").c_str (), "r", stdin);
        freopen ((filename + ".out").c_str (), "w", stdout);
    }

    int n;

    cin >> n;

    ans.assign (n, inf);

    foo (n);

    cout << -1 << endl;
    for (auto it : ans)
        cout << it << ' ';
    cout << endl;
    cout.flush ();

    return 0;
}