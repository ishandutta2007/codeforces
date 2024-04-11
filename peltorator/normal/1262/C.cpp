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

vector<pair<int, int> > ans;
string s;

void put(int pos, char c)
{
    if (s[pos] == c)
        return;
    int x = pos;
    while (x < sz(s) && s[x] != c)
        x++;
#ifdef ONPC
    assert(x < sz(s));
#endif
    ans.push_back({pos, x});
    reverse(s.begin() + pos, s.begin() + x + 1);
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int k;
    cin >> k;
    ans.clear();
    cin >> s;
    int t = 0;
    for (int i = 0; i < k - 1; i++)
        put(2 * i, '('), put(2 * i + 1, ')'), t++;
    for (int j = 2 * k - 2; j < n; j++)
    {
        if (t < n / 2)
        {
            put(j, '(');
            t++;
        }
        else
            put(j, ')');
    }
    cout << sz(ans) << '\n';
    for (auto it : ans)
        cout << it.first + 1 << ' ' << it.second + 1 << '\n';
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