#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    string s;
    cin >> s;
    int k = -1;
    for (int i = 0; i < n; i++)
        if (s[i] == 'R' && s[(i + 1) % sz(s)] == 'L')
            k = i;
    if (k == -1)
    {
        cout << (n + 2) / 3 << '\n';
        return 0;
    }
    string t = s;
    for (int i = 0; i < n; i++)
        s[i] = t[(k + i) % sz(s)];
    int ans = 0;
    for (int i = 0; i < n;)
    {
        if (i + 1 < n && s[i] == 'R' && s[i + 1] == 'L')
            i += 2;
        if (i >= n)
            break;
        int j = i;
        while (j + 1 < n && s[j + 1] == s[i])
            j++;
        if (j + 1 < n && s[j] == 'R' && s[j + 1] == 'L')
            j--;
        ans += (j - i + 2) / 3;
        i = j + 1;
    }
    cout << ans << '\n';
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    cin >> TET;
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