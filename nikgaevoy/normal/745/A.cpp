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

int main ()
{
    if (!interactive)
    {
        freopen ((filename + ".in").c_str (), "r", stdin);
        freopen ((filename + ".out").c_str (), "w", stdout);
    }

    string str;

    cin >> str;

    set<string> was;

    for (int i = 0; i < str.size (); i++)
    {
        was.insert (str);

        reverse (str.begin (), --str.end ());
        reverse (str.begin (), str.end ());
    }

    cout << was.size () << endl;

    return 0;
}