#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>
#include <random>

#define sz(a) (int)((a).size())

using namespace std;

mt19937 rnd(239);

typedef long long ll;
typedef long double ld;

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;
        if (y[0] == 's')
            a++;
        else
            b++;
    }
    if (a < b)
        swap(a, b);
    int i = 1;
    while (true)
    {
        int x = 0, y = 0;
        for (int a = 0; a < i; a++)
            for (int b = 0; b < i; b++)
                if (a % 2 == b % 2)
                    x++;
                else
                    y++;
        if (x >= a && y >= b)
            break;
        i++;
    }
    cout << i << endl;
    return 1;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cerr << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cerr << "_______________________________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}