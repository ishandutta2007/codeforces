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

int main ()
{
    if (!interactive)
    {
        freopen ((filename + ".in").c_str (), "r", stdin);
        freopen ((filename + ".out").c_str (), "w", stdout);
    }

    long long k;

    cin >> k >> k;

    int r = 0;

    while (!(k & 1ll << r))
        r++;

    cout << ++r << endl;

    return 0;
}