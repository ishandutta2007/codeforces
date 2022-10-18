#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) (int)(a).size()


#include <bits/stdc++.h>

using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

int ask(vector<int> a, vector<int> b)
{
    cout << sz(a) << ' ' << sz(b) << ' ';
    for (int i : a)
        cout << i + 1 << ' ';
    for (int i : b)
        cout << i + 1 << ' ';
    cout << endl;
    int x;
    cin >> x;
    return x;
}

vector<int> gen(int l, int r)
{
    vector<int> a;
    for (int i = l; i < r; i++)
        a.push_back(i);
    return a;
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    if (n == 1)
    {
        cout << "-1 0\n";
        return 0;
    }
    int f = ask(gen(0, 1), gen(1, n));
    int l = 1, r = n;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (ask(gen(0, 1), gen(1, mid)) == f)
            r = mid;
        else
            l = mid;
    }
    int v = r - 1;
    vector<int> a;
    for (int i = 0; i < n; i++)
        if (i != v)
            a.push_back(i);
    int x = ask(gen(v, v + 1), a);
    cout << "-1 " << x << endl;
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    cin >> TET;
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