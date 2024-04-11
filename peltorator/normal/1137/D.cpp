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
#include <iomanip>

#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

int solve()
{
    bool ok = 0;
    while (!ok)
    {
        cout << "next 0 1" << endl;
        int len;
        cin >> len;
        while (len--)
        {
            string s;
            cin >> s;
        }
        cout << "next 0" << endl;
        cin >> len;
        while (len--)
        {
            string s;
            cin >> s;
            bool ok1 = 0, ok2 = 0;
            for (int i = 0; i < s.size(); i++)
                if (s[i] == '0')
                    ok1 = 1;
                else if (s[i] == '1')
                    ok2 = 1;
            ok |= (ok1 & ok2);
        }
    }
    while (true)
    {
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        int len;
        cin >> len;
        if (len == 1)
        {
            cout << "done" << endl;
            return 1;
        }
        while (len--)
        {
            string s;
            cin >> s;
        }
    }
    return 1;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cout << "__________________________\n";
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}