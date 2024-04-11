#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
//#define string basic_string<unsigned char>
#define char unsigned char

using namespace std;
//mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;
    vector<int> cnt;
    for (int i = 0; i < n; i++)
    {
        map<int, int> q;
        int j = i;
        int good = -1;
        int kek = 0;
        while (j < n)
        {
            if (a[j] < 0)
            {
                int x = -a[j];
                if (q[x] != 1)
                    break;
                else
                    q[x] = 2, kek--;
            }
            else
            {
                int x = a[j];
                if (q[x] == 0)
                    q[x] = 1, kek++;
                else
                    break;
            }
            if (kek == 0)
                good = j;
            j++;
        }
        if (good == -1)
        {
            cout << "-1\n";
            return 0;
        }
        cnt.push_back(good - i + 1);
        i = good;
    }
    cout << sz(cnt) << '\n';
    for (ll i : cnt)
        cout << i << ' ';
    cout << '\n';
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    // cin >> TET;
    for (int i = 1; i <= TET; i++)
    {
        if (solve())
            break;
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}