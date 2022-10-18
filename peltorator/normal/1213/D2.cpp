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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<bool> vb;

const int N = 2e5 + 239;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<vector<int> > v(N);
    for (int i : a)
    {
        int j = i;
        int x = 0;
        while (true)
        {
            v[j].push_back(x);
            if (!j)
                break;
            x++;
            j /= 2;
        }
    }
    int ans = 1e9;
    for (int i = 0; i < N; i++)
    {
        if (sz(v[i]) < k)
            continue;
        sort(v[i].begin(), v[i].end());
        int cnt = 0;
        for (int j = 0; j < k; j++)
            cnt += v[i][j];
        ans = min(ans, cnt);
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