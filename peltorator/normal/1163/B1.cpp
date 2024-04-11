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

const int N = 3e5;

int cnt[N];
int v[N];

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 0; i < N; i++)
        cnt[i] = v[i] = 0;
    int ans = 1;
    set<int> q;
    for (int i = 0; i < n; i++)
    {
        v[cnt[a[i]]] -= cnt[a[i]];
        cnt[a[i]]++;
        q.insert(a[i]);
        int x = cnt[a[i]];
        v[x] += x;
        int y = cnt[a[0]];
        if (sz(q) == 1 || v[1] == i + 1 || (v[x] == i && v[1] == 1) || (v[x] == i - x && v[x + 1] == x + 1) || (v[y] == i && v[1] == 1) || (v[y] == i - y && v[y + 1] == y + 1))
            ans = i + 1;
    }
    cout << ans << endl;
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