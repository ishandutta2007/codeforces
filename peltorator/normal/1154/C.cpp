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

int t[] = {0, 1, 2, 0, 2, 1, 0};

int solve()
{
    vector<int> a(3);
    if (!(cin >> a[0]))
        return 1;
    cin >> a[1] >> a[2];
    int ans = 0;
    int x = min(a[0] / 3, min(a[1] / 2, a[2] / 2));
    a[0] -= 3 * x;
    a[1] -= 2 * x;
    a[2] -= 2 * x;
    for (int i = 0; i < 7; i++)
    {
        vector<int> b = a;
        int cur = i;
        while (true)
        {
            if (b[t[cur % 7]]-- == 0)
                break;
            cur++;
        }
        ans = max(ans, cur - i);
    }
    cout << ans + 7 * x << endl;
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