#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>

using namespace std;
//mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    string s;
    cin >> s;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    const int N = 1e4;
    vector<int> cnt(N, 0);
    for (int i = 0; i < n; i++)
    {
        int cur = s[i] - '0';
        for (int j = 0; j < N; j++)
        {
            if (j >= b[i] && (j - b[i]) % a[i] == 0)
                cur ^= 1;
            cnt[j] += cur;
        }
    }
    int ans = 0;
    for (int i : cnt)
        ans = max(ans, i);
    cout << ans << endl;
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