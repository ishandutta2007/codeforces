#ifdef ONPC
    # define _GLIBCXX_DEBUG
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

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int b, a;
    cin >> b >> a;
    vector<int> s(n);
    for (int &i : s)
        cin >> i;
    int pos = 0;
    int A = a;
    while (pos < n)
    {
        if (a + b == 0)
            break;
        if (b && ((s[pos] && a != A) || !a))
        {
            b--;
            a = min(A, a + s[pos]);
        }
        else
            a--;
        pos++;
    }
    cout << pos << endl;
    return 0;
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