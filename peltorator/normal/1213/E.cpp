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

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    string s;
    cin >> s;
    string t;
    cin >> t;
    if (s[0] == s[1])
        swap(s, t);
    cout << "YES\n";
    if (s[0] == s[1])
    {
        for (int i = 0; i < n; i++)
            cout << "abc";
        cout << endl;
        return 0;
    }
    map<char, char> q, revq;
    set<int> qq = {'a', 'b', 'c'};
    qq.erase(s[0]);
    qq.erase(s[1]);
    char c = *qq.begin();
    q[c] = 'c';
    revq['c'] = c;
    q[s[0]] = 'a';
    revq['a'] = s[0];
    q[s[1]] = 'b';
    revq['b'] = s[1];
    string ans = "";
    t[0] = q[t[0]];
    t[1] = q[t[1]];
    if (t[0] != t[1])
    {
        if (t == "cb" || t == "ba")
        {
            for (char c : {'b', 'c', 'a'})
                for (int i = 0; i < n; i++)
                    ans.push_back(c);
        }
        else
        {
            for (char c : {'c', 'b', 'a'})
                for (int i = 0; i < n; i++)
                    ans.push_back(c);
        }
    }
    else if (t[0] != 'a')
    {
        for (int i = 0; i < n; i++)
            ans.push_back('c'), ans.push_back('b');
        for (int i = 0; i < n; i++)
            ans.push_back('a');
    }
    else
    {
        for (int i = 0; i < n; i++)
            ans.push_back('b');
        for (int i = 0; i < n; i++)
            ans.push_back('c'), ans.push_back('a');
    }
    for (int i = 0; i < sz(ans); i++)
        cout << revq[ans[i]];
    cout << endl;
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