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
const int inf = int (1e9) + 7;

int main ()
{
    if (!interactive)
    {
        freopen ((filename + ".in").c_str (), "r", stdin);
        freopen ((filename + ".out").c_str (), "w", stdout);
    }

    int n;

    cin >> n;

    string s;

    cin >> s;

    string sam = "ACGT";
    vector<int> cnt (4);

    for (auto it : s)
        for (int i = 0; i < sam.size (); i++)
            if (sam[i] == it)
                cnt[i]++;

    int t = s.size () / 4;

    bool good = s.size () % 4 == 0;

    for (auto it : cnt)
        good &= it <= t;

    if (good)
    {
        for (auto &it : s)
            if (it == '?')
                for (int i = 0; i < cnt.size (); i++)
                    if (cnt[i] < t)
                    {
                        cnt[i]++;
                        it = sam[i];

                        break;
                    }

        cout << s << endl;
    }
    else
        cout << "===" << endl;

    return 0;
}