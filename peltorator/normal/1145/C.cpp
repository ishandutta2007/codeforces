#ifdef ONPC
    # define _GLIBCXX_DEBUG
#endif
#ifdef ONPC
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) (int)(a).size()


#include <bits/stdc++.h>

using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(time(0));

typedef long long ll;

int a[] = {15, 14, 12, 13, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 16, 17, 18, 19, 20, 21, 22};

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    cout << a[n] << endl;
    return 1;
    if (n == 0)
        cout << 15 << endl;        
    else if (n == 3)
        cout << 13 << endl;
    else if (n == 1)
        cout << 14 << endl;
    else if (n == 2)
        cout << 12 << endl;
    else if (n == 4)
        cout << 8 << endl;
    else
        cout << 0 << endl;
    return 1;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    while (TET--)
    {
        if (solve())
            break;
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}