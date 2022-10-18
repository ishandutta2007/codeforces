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

#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

#define int long long

int solve()
{
    int a;
    if (!(cin >> a))
        return 1;
    int b;
    cin >> b;
    int k = 0;
    while (k * (k + 1) / 2 <= a + b)
        k++;
    k--;
    vector<int> p, q;
    for (int i = k; i > 0; i--)
        if (a >= i)
        {
            a -= i;
            p.push_back(i);
        }
        else
        {
            b -= k;
            q.push_back(i);
        }
    cout << p.size() << endl;
    for (int i : p)
        cout << i << ' ';
    cout << endl << q.size() << endl;
    for (int i : q)
        cout << i << ' ';
    cout << endl;
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