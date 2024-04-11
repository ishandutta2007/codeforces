#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>

using namespace std;
mt19937 rnd(239);

#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define ob pop_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<int> a(n);
    set<int> q;
    for (int &i : a)
        cin >> i, q.insert(i);
    if (sz(q) == n)
    {
        cout << "0\n";
        return 0;
    }
    map<int, int> l, r;
    int L = 0;
    l[a[0]]++;
    while (l[a[L + 1]] == 0)
    {
        l[a[L + 1]]++;
        L++;
    }
    int ans = n - L - 1;
    for (int R = n - 1; R >= 0; R--)
    {
        if (r[a[R]] != 0)
            break;
        while (l[a[R]])
        {
            l[a[L]]--;
            L--;
        }
        r[a[R]]++;
        ans = min(ans, R - L - 1);
    }
    cout << ans << '\n';
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
}