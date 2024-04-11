#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>
#include <random>
#include <iomanip>

#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

vector<int> perm = {1, 2, 0};

string ask(string s)
{
    cout << "? " << s << endl;
    string t = "";
    cin >> t;
    //for (int i = 0; i < s.size(); i++)
      //  t += s[perm[i]];
    return t;
}

int solve()
{
    string s;
    cin >> s;
    int n = s.size();
    string t1 = s, t2 = s, t3 = s;
    for (int i = 0; i < n; i++)
    {
        t1[i] = (i % 26 + 'a');
        t2[i] = ((i / 26) % 26 + 'a');
        t3[i] = ((i / 26 / 26) % 26 + 'a');
    }
    string s1 = ask(t1);
    string s2 = ask(t2);
    string s3 = ask(t3);
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        v[i] = (int)(s1[i] - 'a') + (int)(s2[i] - 'a') * 26 + (int)(s3[i] - 'a') * 26 * 26;
    cout << "! ";
    string t = s;
    for (int i = 0; i < n; i++)
        t[v[i]] = s[i];
    cout << t << endl;
    return 1;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cout << "__________________________\n";
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}