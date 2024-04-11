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

const int N = 212345;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int qq;
    cin >> qq;
    vector<int> a(n, 0);
    vector<int> f(N, -1), s(N, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (f[a[i]] == -1)
            f[a[i]] = i;
        s[a[i]] = i;
    }
    vector<int> cnt(n, 0);
    for (int i = 0; i < N; i++)
        if (f[i] != -1)
        {
            cnt[f[i]]++;
            cnt[s[i]]--;
        }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int z = cnt[j];
        map<int, int> q;
        q[a[i]] = 1;
        int bst = 1;
        while (z)
        {
            j++;
            bst = max(bst, ++q[a[j]]);
            z += cnt[j];
        }
        ans += (j - i + 1) - bst;
        i = j;
    }
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