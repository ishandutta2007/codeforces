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
    string s;
    if (!(cin >> s))
        return 1;
    if (s.size() < 4)
    {
        cout << "Impossible\n";
        return 0;
    }
    set<char> q;
    int n = s.size();
    for (int i = 0; i < n; i++)
        if (n % 2 == 0 || i != n / 2)
            q.insert(s[i]);
    if (q.size() == 1)
    {
        cout << "Impossible\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        bool ok = 1;
        for (int j = 0; j < n && ok; j++)
            if (s[(i + j) % n] != s[(n - j - 1 + i) % n])
                ok = 0;
        bool kek = 0;
        for (int j = 0; j < n; j++)
            if (s[j] != s[(i + j) % n])
                kek = 1;
        if (ok && kek)
        {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 2 << endl;
    return 0;
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